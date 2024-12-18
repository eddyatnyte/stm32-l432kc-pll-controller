/*
 * SSH1106.h
 *
 *  Created on: Mar 13, 2024
 *      Author: E.Boloban
 */

#ifndef SRC_DISPLAY_SSH1106_H_
#define SRC_DISPLAY_SSH1106_H_

#include <stdint.h>


#include "fonts.h"
#include "ssd1306.h"

/**
 * @brief Enumeration for different font sizes.
 */
enum eFontSize {
	SMALL, /**< Small font size. */
	MEDIUM, /**< Medium font size. */
	LARGE /**< Large font size. */
};

/**
 * @brief Enumeration for different colors.
 */
enum eColor {
	BLACK, /**< Black color. */
	WHITE /**< White color. */
};

/**
 * @brief This is a Wrapper-Class for the 1.3" I2C-Display (128x64).
 */
class SSH1106 {
private:
	eFontSize m_size; /**< Font size. */
	eColor m_color; /**< Font color. */

	/**
	 * @brief Fills entire LCD with desired color.
	 * SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen.
	 */
	void fillScreen();

public:
	/**
	 * @brief Initializes SSD1306 LCD.
	 * Is initialized with small font size and white font color.
	 */
	SSH1106();

	/**
	 * @brief Puts string to internal RAM.
	 *
	 * @param text String to be written.
	 */
	void write(const char *text);


	/**
	 * @brief Sets cursor pointer to desired location for strings.
	 *
	 * @param x X location.
	 * @param y Y location.
	 */
	void setCursor(uint16_t x, uint16_t y);

	/**
	 * @brief Sets font color.
	 *
	 * @param color Font color.
	 */
	void setColor(eColor color);

	/**
	 * @brief Sets font size.
	 *
	 * @param size Font size.
	 */
	void setFontSize(eFontSize size);

	/**
	 * @brief Draws a line.
	 *
	 * @param x0 Starting X coordinate.
	 * @param y0 Starting Y coordinate.
	 * @param x1 Ending X coordinate.
	 * @param y1 Ending Y coordinate.
	 */
	void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

	/**
	 * @brief Updates buffer from internal RAM to LCD.
	 * This function must be called each time you do some changes to LCD,
	 * to update buffer from RAM to LCD.
	 */
	void updateDisplay();

	/**
	 * @brief Clears the Display.
	 */
	void clearDisplay();
};

#endif /* SRC_DISPLAY_SSH1106_H_ */
