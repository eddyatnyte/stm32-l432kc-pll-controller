/*
 * RotaryEncoder.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: bolob
 */

#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(TIM_HandleTypeDef *htim, int16_t maxPosition,
		int16_t minPosition) {
	m_htim = htim;
	m_position = 0;
	m_maxPosition = maxPosition;
	m_minPosition = minPosition;
	m_lastEncoded = __HAL_TIM_GET_COUNTER(m_htim);
	HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
}

int32_t RotaryEncoder::getPosition() {
	return m_position;
}

void RotaryEncoder::resetPosition() {
	m_position = 0;
}

void RotaryEncoder::updatePosition() {
	uint32_t value = __HAL_TIM_GET_COUNTER(m_htim);
	int32_t diff = static_cast<int32_t>(value - m_lastEncoded);
	if (diff > 0) {
		m_position++;
	} else if (diff < 0) {
		m_position--;
	}

	// Limit the position in it's range
	if (m_position > m_maxPosition) {
		m_position = m_maxPosition;
	} else if (m_position < m_minPosition) {
		m_position = m_minPosition;
	}

	m_lastEncoded = value;
}
