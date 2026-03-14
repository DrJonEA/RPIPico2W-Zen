/*
 * Ring.cpp
 *
 *  Created on: 12 Nov 2025
 *      Author: jondurrant
 */

#include "Ring.h"
#include <math.h>

Ring::~Ring() {
	// TODO Auto-generated destructor stub
}


Ring::Ring(PicoLed::PicoLedController *leds, PicoLed::Color color,  float radOffset){
	setLeds(leds);
	setColor(color);
	setRadOffset(radOffset);
}


void Ring::setLeds(PicoLed::PicoLedController *leds){
	pLeds = leds;
}

void Ring::setColor(PicoLed::Color color){
	xColor = color;
}

void Ring::setRadOffset(float radOffset){
	xRadOffset = radOffset;
}

void Ring::drawArc(float rad){
	if (pLeds == NULL)
		return;

	float startRad = rad + xRadOffset;
	if (startRad > M_PI * 2){
		startRad = startRad - M_PI * 2;
	}
	if (startRad < 0.0){
		startRad = startRad + M_PI * 2;
	}

	int count = pLeds->getNumLeds();
	int start = (float)count / (M_PI * 2) * startRad;
	int len = count /4;

	pLeds->clear();
	for (int i=0; i < len; i++){
		pLeds->setPixelColor(
				(start + i) % count,
				xColor
				);
	}
}

void Ring::fill(uint8_t r, uint8_t g, uint8_t b){
	pLeds->fill(PicoLed::RGB(r, g, b));
}
