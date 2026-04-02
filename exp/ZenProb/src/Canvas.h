/*
 * Canvas.h
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#ifndef EXP_ANIMATIONS_SRC_CANVAS_H_
#define EXP_ANIMATIONS_SRC_CANVAS_H_

#include "pico/stdlib.h"
#include <stdexcept>
#include <PicoLed.hpp>


#define LEDS_PIN 15
#define LEDS_LENGTH 241

#define FRAME_SIZE 17

class Canvas {
public:
	Canvas(PicoLed::PicoLedController *p);
	virtual ~Canvas();

	uint8_t getRows();
	uint8_t getColumns();

	PicoLed::PicoLedController * getController();
	PicoLed::PicoLedController slice(uint start, uint end);

	void show(uint8_t alpha= 0xFF);
	void clear(uint32_t c=0x00);

	void hzLine(uint8_t y=8, uint32_t c=0xFFFFFF);
	void vtLine(uint8_t x=8, uint32_t c=0xFFFFFF);

	void drawImg(const uint32_t *img);
	void setPixel(uint8_t x, uint8_t  y, uint32_t c = 0xFFFFFF);

private:
	PicoLed::PicoLedController  *pController;
	uint32_t framebuffer[FRAME_SIZE][FRAME_SIZE] = {0};
};

#endif /* EXP_ANIMATIONS_SRC_CANVAS_H_ */
