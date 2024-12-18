/**
 * @file RotaryEncoder.h
 * @brief Header file for RotaryEncoder class.
 */

#ifndef SRC_ROTARYENCODER_H_
#define SRC_ROTARYENCODER_H_

#include "../Display/SSH1106.h" // Include necessary headers
#include <sstream>
#include <tim.h>

using namespace std;

/**
 * @class RotaryEncoder
 * @brief Class for interfacing with a rotary encoder.
 */
class RotaryEncoder {
private:
	TIM_HandleTypeDef *m_htim; /**< Pointer to TIM_HandleTypeDef for the timer used by the encoder. */
	int32_t m_position; /**< Current position of the rotary encoder. */
	uint32_t m_lastEncoded; /**< Last encoded value of the rotary encoder. */
	int16_t m_maxPosition;
	int16_t m_minPosition;

public:

	/**
	 * @brief Constructor for the RotaryEncoder class.
	 *
	 * This constructor initializes a RotaryEncoder object with the specified parameters.
	 *
	 * @param htim Pointer to the TIM_HandleTypeDef structure for the timer used by the encoder.
	 * @param maxPosition Maximum position value for the encoder. Defaults to 120 if not specified.
	 * @param minPosition Minimum position value for the encoder. Defaults to -120 if not specified.
	 */
	RotaryEncoder(TIM_HandleTypeDef *htim, int16_t maxPosition = 120,
			int16_t minPosition = 0);

	/**
	 * @brief Get the current position of the rotary encoder.
	 * @return Current position of the rotary encoder.
	 */
	int32_t getPosition();

	/**
	 * @brief Reset the position of the rotary encoder to zero.
	 */
	void resetPosition();

	/**
	 * @brief Update the position of the rotary encoder.
	 * This method should be called at a maximum frequency of 10Hz
	 * to maintain accuracy. Failure to do so may result in decreased accuracy.
	 */
	void updatePosition();
};

#endif /* SRC_ROTARYENCODER_H_ */
