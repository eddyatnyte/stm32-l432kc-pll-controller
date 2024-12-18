/*
 * TestApplication.cpp
 *
 *  Created on: Mar 16, 2024
 *      Author: E. Boloban
 */

#include "TestApplication.h"

void TestApplication::testPeriphals() {
	RotaryEncoder encoder(&htim1);
	SSH1106 display;

	// Initialize next update time
	uint32_t nextUpdate = HAL_GetTick() + 150;

	// Initialize position variable to store previous position
	int32_t prevPosition = encoder.getPosition();

	while (true) {
		// Check if it's time to update the display
		if (HAL_GetTick() >= nextUpdate) {
			// Clear/update the display only if the position has changed
			if (encoder.getPosition() != prevPosition) {
				display.clearDisplay();
				display.setCursor(1, 8);
				display.write("Phase: ");
				stringstream ss;
				ss << encoder.getPosition();
				display.write(ss.str().c_str());
				display.write(" Grad");
				display.updateDisplay();
			}

			// Update previous position
			prevPosition = encoder.getPosition();

			// Update position periodically
			encoder.updatePosition();

			// Increment next update time
			nextUpdate += 100;
		}

		// Check for button press to reset encoder position
		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_RESET) {
			encoder.resetPosition();
		}
	}
}

void TestApplication::testPLL() {
	SSH1106 display;

	// Initialize next update time
	uint32_t nextUpdate = HAL_GetTick() + 1000;
	while (true) {

		// Check if it's time to update the display
		if ((HAL_GetTick() >= nextUpdate)) {
			stringstream sf;
			stringstream sT;

			// get the current Frequency
			double f = PLL_Y.Frequency;

			// calculate the current period time
			double T = 1000 / f;

			// round the numbers to the second position
			f = std::round(f * 100) / 100;
			T = std::round(T * 100) / 100;

			// convert the measured values into a string
			sT << T;
			sf << f;

			// write the processed frequency in the first row
			display.setCursor(1, 8);
			display.write("f: ");
			display.write(sf.str().c_str());
			display.write(" Hz"),

			// write the processed period time in the second row
			display.setCursor(1, 18);
			display.write("T: ");
			display.write(sT.str().c_str());
			display.write(" ms"),

			// update the display and set time for next update
			display.updateDisplay();
			nextUpdate += 100;
		}
	}
}

void TestApplication::testInput() {
	SSH1106 display;
	stringstream ss;

	// current settings
	uint8_t source = L1;
	uint8_t edge = RISING;

	// tells if a change for the settings has been made
	bool changeMade = true;

	// saves the previous input state for PA1[0], PA2[1] and PA7[2]
	GPIO_PinState prevState[3] = { GPIO_PIN_RESET, GPIO_PIN_RESET,
			GPIO_PIN_RESET };

	// saves the current input state for PA1[0], PA2[1] and PA7[2]
	GPIO_PinState currState[3] = { GPIO_PIN_RESET, GPIO_PIN_RESET,
			GPIO_PIN_RESET };

	// Initialize next update time
	uint32_t nextUpdate = HAL_GetTick() + 150;

	while (true) {
		// Check if it's time to update the display
		if ((HAL_GetTick() >= nextUpdate) && changeMade) {
			// Clear/update the display only if the position has changed
			display.clearDisplay();

			// sets cursor to the next line
			display.setCursor(1, 10);
			display.write("testInput()");

			// sets cursor to the next line
			display.setCursor(1, 20);
			display.write("Schalten auf: ");

			// writes the current input source on the display
			switch (source) {
			case L1:
				display.write("L1");
				break;
			case L2:
				display.write("L2");
				break;
			case L3:
				display.write("L3");
				break;
			}

			// sets cursor to the next line
			display.setCursor(1, 30);

			// writes the current type of the edge on the display
			switch (edge) {
			case RISING:
				display.write("pos. ");
				break;
			case FALLING:
				display.write("neg. ");
				break;
			}

			display.write("Halbwelle");
			display.updateDisplay();

			// resets the flag
			changeMade = false;

			// Increment next update time
			nextUpdate += 100;
		}

		// saves the current pin-states
		currState[0] = debounce(GPIOA, GPIO_PIN_1);
		currState[1] = debounce(GPIOA, GPIO_PIN_2);
		currState[2] = debounce(GPIOA, GPIO_PIN_7);

		// If PA1 was pressed
		if ((currState[0] == GPIO_PIN_SET)
				&& (prevState[0] == GPIO_PIN_RESET)) {
			// increment to the next state
			source++;

			// resets the counter to the initial value (0)
			source %= 3;

			// sets the flag, that the settings have been changed
			changeMade = true;
		}

		// if PA2 was pressed
		if ((currState[1] == GPIO_PIN_SET)
				&& (prevState[1] == GPIO_PIN_RESET)) {
			// increment to the next state
			edge++;

			// resets the counter to the initial value (0)
			edge %= 2;

			// sets the flag, that the settings have been changed
			changeMade = true;
		}

		for (uint8_t i = 0; i < 3; i++) {
			prevState[i] = currState[i];
		}
	}
}

void TestApplication::testPhaseDetection() {
	RotaryEncoder encoder(&htim1);
	SSH1106 display;

	// Initialize next update time
	uint32_t nextUpdate = HAL_GetTick() + 100;

	// a buffer to save the numerical values
	char buffer[16];

	// time difference between the phase and zero-crossing of the input signal
	double phaseDiff = 0;

	double offset = 0;

	bool startTrig = false;

	// saves the previous input state for PA1[0], PA2[1] and PA7[2]
	GPIO_PinState prevState = GPIO_PIN_RESET;

	// saves the current input state for PA1[0], PA2[1] and PA7[2]
	GPIO_PinState currState = GPIO_PIN_RESET;

	while (true) {
		// Check if it's time to update the display
		if (HAL_GetTick() >= nextUpdate) {
			// Get the current frequency
			double f = PLL_Y.Frequency;

			// Calculate the current period time
			double T = 1000.0 / f;

			// Round the numbers to two decimal places
			f = std::round(f * 100) / 100;
			T = std::round(T * 100) / 100;

			// Update display with frequency
			display.setCursor(1, 8);
			display.write("f: ");
			snprintf(buffer, sizeof(buffer), "%.1f Hz", f);
			display.write(buffer);

			// Update display with period time
			display.setCursor(1, 18);
			display.write("T: ");
			snprintf(buffer, sizeof(buffer), "%.1f ms", T);
			display.write(buffer);

			// Update display with phase
			display.setCursor(1, 28);
			display.write("Phase: ");
			snprintf(buffer, sizeof(buffer), "%03d Grad",
					(int) encoder.getPosition());
			display.write(buffer);

			// Update position periodically
			encoder.updatePosition();

			// Update the display and set time for next update
			display.updateDisplay();
			nextUpdate += 100;
		}

		currState = debounce(GPIOA, GPIO_PIN_7);

		//calculates the time shift
		phaseDiff = ((1e6 / PLL_Y.Frequency) / 360) * encoder.getPosition();

		// If the Start-Button was pressed,
		if ((currState == GPIO_PIN_SET) && (prevState == GPIO_PIN_RESET)) {
			// save the trigger
			startTrig = true;
		}

		// If the phase angle is nearly zero,
		if ((PLL_Y.Phase >= 0) && (PLL_Y.Phase <= 10)) {

			// and the Start-Button was once pressed
			if (startTrig) {
				// turn all Interrupts off
				__disable_irq();

				// compensate the offset between the input signal and PLL
				offset = (1e6 / PLL_Y.Frequency) - 930;
				delay_us(offset);

				// A pulse is given on PA5 (A4)
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
				delay_us(phaseDiff);

				// A pulse is given on PA6 (A5)
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);

				startTrig = false;

				// turn all Interrupts on
				__enable_irq();
			}

		} else {
			// Otherwise, a LOW level is applied
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
		}

		// If the Encoder was pressed,
		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_RESET) {
			// reset the current value
			encoder.resetPosition();
		}

		prevState = currState;
	}
}

GPIO_PinState TestApplication::debounce(GPIO_TypeDef *GPIOx,
		uint16_t GPIO_Pin) {

	// Wait for debounce time
	HAL_Delay(DEBOUNCE_DELAY_MS);
	return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

void TestApplication::delay_us(uint32_t us) {
	__HAL_TIM_SET_COUNTER(&htim6, 0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim6) < us)
		;  // wait for the counter to reach the us input in the parameter
}
