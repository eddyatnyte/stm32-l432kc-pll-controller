/*
 * TestApplication.h
 *
 *  Created on: Mar 16, 2024
 *      Author: E.Boloban
 */

#ifndef SRC_TESTAPPLICATION_H_
#define SRC_TESTAPPLICATION_H_

#include "Display/SSH1106.h"
#include "Encoder/RotaryEncoder.h"
#include "adc.h"
#include "tim.h"
#include "PLL/PLL.h"
#include <iomanip>
#include <cmath>

#define DEBOUNCE_DELAY_MS 3
constexpr double pi = 3.14159265358979323846;

/**
 * Determines the input source on which the phase should be applied
 */
enum eInputSource {
	L1,/**< L1 */
	L2,/**< L2 */
	L3 /**< L3 */
};

/**
 * Determines on which edge the phase should be applied
 */
enum eEdge {
	RISING,/**< RISING */
	FALLING/**< FALLING */
};

class TestApplication {
public:
	/**
	 * This function tests the peripheral devices connected to the microcontroller.
	 * The current value of the encoder is displayed on the screen.
	 * To reset the current value, press the encoder switch (Encoder-SW).
	 * For more information about the display and encoder,
	 * refer to the documentation in the header file.
	 */
	void testPeriphals();

	/**
	 * This functions tests the PLL implemented via Simulink.
	 * The returned frequency will be read out and then printed on the display.
	 * Testwise the period time will be calculated and also printed on the display.
	 */
	void testPLL();

	/**
	 * This function tests the input buttons.
	 * Depending on the running code, following changes will be made:
	 * PA1: changes the input source, on which the phase should be applied
	 * PA2: sets up, whether the phase should be applied on a falling or rising edge
	 * PA7: Starts the application
	 */
	void testInput();

	/**
	 * This function tests the PLL in combination with the encoder.
	 * The encoder sets the phase at which a HIGH pulse will be generated on PA6.
	 * The current frequency of the input signal will be displayed.
	 */
	void testPhaseDetection();

private:
	/**
	 * This functions implements a debouncer for the input keys
	 *
	 * @param GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L4 family
	 * @param GPIO_Pin GPIO_Pin specifies the port bit to read.
	 *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
	 * @return the debounced input port pin value
	 */
	GPIO_PinState debounce(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

	/**
	 *
	 *
	 * @param us delay in Microseconds
	 */
	void delay_us(uint32_t us);
};

/**
 * Runs the chosen tests
 */
extern "C" void runTest() {
	TestApplication myTest;
//	myTest.testPeriphals();
//	myTest.testPLL();
//	myTest.testInput();
	myTest.testPhaseDetection();

}

#endif /* SRC_TESTAPPLICATION_H_ */
