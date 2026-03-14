/*
 * Snowflakes.cpp
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#include "Snowflakes.h"
#include <cstring>
#include <stdlib.h>

#define STEP_TIME 2000


Snowflakes::Snowflakes() {
	// TODO Auto-generated constructor stub

}

Snowflakes::~Snowflakes() {
	// TODO Auto-generated destructor stub
}

Snowflakes::Snowflakes(Canvas *p){
	setCanvas(p);
}


void Snowflakes::poll(){
	uint32_t now = to_ms_since_boot (get_absolute_time());
	if ((xLast + STEP_TIME) > now){
		return;
	}
	xLast = now;
	pCanvas->clear();

	uint32_t c = xColours[xColour++];
	if (xColour >= SNOWFLAKE_COLOURS){
		xColour=0;
	}
	uint8_t xRows = pCanvas->getRows();
	uint8_t xCols = pCanvas->getColumns();

	// Generate 1/8th of the snowflake (top-left triangle)
	for (int i = 0; i <= xCols / 2; i++) {
		for (int j = 0; j <= i; j++) {
			uint32_t pixel = (rand() % 2) ? c : 0;
			pCanvas->setPixel(i, j, pixel);

			// Mirror across vertical
			pCanvas->setPixel(i, xRows - 1 - j,  pixel);
			// Mirror across horizontal
			pCanvas->setPixel(xCols - 1 - i, j,  pixel);
			// Mirror across both
			pCanvas->setPixel(xCols - 1 - i, xRows - 1 - j,  pixel);
			// Mirror across diagonal
			pCanvas->setPixel(j, i,  pixel);
			pCanvas->setPixel(xRows - 1 - j, i,  pixel);
			pCanvas->setPixel(j, xCols - 1 - i,  pixel);
			pCanvas->setPixel(xRows - 1 - j, xCols - 1 - i,  pixel);
		}
	}
	pCanvas->show();
}

uint32_t Snowflakes::xColours[SNOWFLAKE_COLOURS]={
		0xFFFFFF,
		0xA0A0FF,
		0xA0FFA0,
		0xFFFFA0,
		0x50A0FF,
		0x1010FF,
		0x50500
};
