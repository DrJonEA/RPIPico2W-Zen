/*
 * Ring.h
 *
 *  Created on: 12 Nov 2025
 *      Author: jondurrant
 */

#ifndef EXP_ROTATINGARCS_SRC_RING_H_
#define EXP_ROTATINGARCS_SRC_RING_H_

#include <PicoLed.hpp>
#include <VirtualStrip.hpp>


class Ring {
public:
	Ring(PicoLed::PicoLedController *leds, PicoLed::Color color,  float radOffset=0.0);
	virtual ~Ring();
	void setLeds(PicoLed::PicoLedController *leds);
	void setColor(PicoLed::Color color);
	void setRadOffset(float radOffset);

	void drawArc(float rad);
	void fill(uint8_t r, uint8_t g, uint8_t b);

private:
	PicoLed::PicoLedController *pLeds = NULL;
	PicoLed::Color xColor;
	float xRadOffset = 0.0;
};

#endif /* EXP_ROTATINGARCS_SRC_RING_H_ */
