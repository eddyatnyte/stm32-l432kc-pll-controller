/*
 * SSH1106.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: E.Boloban
 */

#include "SSH1106.h"

void SSH1106::fillScreen() {
	switch (m_color) {
	case WHITE:
		SSD1306_Fill(SSD1306_COLOR_WHITE);
		break;
	case BLACK:
		SSD1306_Fill(SSD1306_COLOR_BLACK);
		break;
	}
}

SSH1106::SSH1106() {
	SSD1306_Init();
	clearDisplay();
	m_color = WHITE;
	m_size = SMALL;
}

void SSH1106::write(const char *text) {
	switch (m_color) {
	case WHITE:
		switch (m_size) {
		case SMALL:
			SSD1306_Puts(text, &Font_7x10, SSD1306_COLOR_WHITE);
			break;
		case MEDIUM:
			SSD1306_Puts(text, &Font_11x18, SSD1306_COLOR_WHITE);
			break;
		case LARGE:
			SSD1306_Puts(text, &Font_16x26, SSD1306_COLOR_WHITE);
			break;
		}
		break;
	case BLACK:
		switch (m_size) {
		case SMALL:
			SSD1306_Puts(text, &Font_7x10, SSD1306_COLOR_BLACK);
			break;
		case MEDIUM:
			SSD1306_Puts(text, &Font_11x18, SSD1306_COLOR_BLACK);
			break;
		case LARGE:
			SSD1306_Puts(text, &Font_16x26, SSD1306_COLOR_BLACK);
			break;
		}
		break;
	}
}

void SSH1106::setCursor(uint16_t x, uint16_t y) {
	SSD1306_GotoXY(x, y);
}

void SSH1106::setColor(eColor color) {
	m_color = color;
}

void SSH1106::setFontSize(eFontSize size) {
	m_size = size;
}

void SSH1106::drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	switch (m_color) {
	case WHITE:
		SSD1306_DrawLine(x0, y0, x1, y1, SSD1306_COLOR_WHITE);
		break;
	case BLACK:
		SSD1306_DrawLine(x0, y0, x1, y1, SSD1306_COLOR_BLACK);
		break;
	}
}

void SSH1106::updateDisplay() {
	SSD1306_UpdateScreen();
}


void SSH1106::clearDisplay() {
	SSD1306_Clear();
}
