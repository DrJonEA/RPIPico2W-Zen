/*
 * ZenLamps.cpp
 *
 *  Created on: 14 Mar 2026
 *      Author: jondurrant
 */

#include "ZenLamps.h"
#include "pico/rand.h"

ZenLamps::ZenLamps(Canvas *p) {
	setCanvas(p);
	xLines[0] = { 	3,		0x80,		0x80,		0};
	xLines[1] = { 	3,		0x80,		0x80,		0};
	xLines[2] = { 	3,		0x80,		0x80,		0};
	xLines[3] = { 	3,		0x80,		0x80,		0};
	xLines[4] = { 	3,		0x80,		0x80,		0};
	xLines[5] = { 	3,		0x80,		0x80,		0};
	xLines[6] = { 	3,		0x80,		0x80,		0};
	xLines[7] = { 	8,		0x80,		0x80,		0};
	xLines[8] = { 12,		0xF0,		0x80,		0};
	xLines[9] = { 	8,		0x80,		0x80,		0};
	xLines[10] = { 3,		0x80,		0x80,		0};
	xLines[11] = { 	3,		0x80,		0x80,		0};
	xLines[12] = { 	3,		0x80,		0x80,		0};
	xLines[13] = { 3,		0x80,		0x80,		0};
	xLines[14] = { 3,		0x80,		0x80,		0};
	xLines[15] = { 	3,		0x80,		0x80,		0};
	xLines[16] = { 3,		0x80,		0x80,		0};
}

ZenLamps::~ZenLamps() {
	// TODO Auto-generated destructor stub
}

void ZenLamps::poll(){
	uint8_t alpha = 0x00;

	uint8_t steps = 0xFF - xSpeed;

	if (xSeq >= steps){
		xSeq = 0;
	}

	uint8_t half = steps/2;
	if (xSeq < half){
		//Brighten
		alpha = ((float)xSeq/ (float)half) * 255.0 ;
	} else {
		alpha = ((float)(half - (xSeq - half))/ (float)half) * 255.0 ;
	}
	if (xSeq == 0){
		doZen(alpha);
	} else {
		pCanvas->show(alpha);
	}
	xSeq++;
}


uint32_t ZenLamps::getColor(){
	uint32_t c = xColor;

	if (xColorVar > 0){
		for (int i=0; i < 3; i++){
			uint8_t v = (xColorVar >> (8 *i )) && 0xFF;
			uint8_t m = get_rand_32 () % v;
			if (m > (v/2)){
				m = m - (v/2);
				c = c - (m << (8*i));
			} else {
				c = c + (m << (8*i));
			}
		}
	}
	return c;
}

void ZenLamps::doZen(uint8_t alpha){


	pCanvas->clear();

	for (uint line = 0; line < ZEN_ROWS; line++){
	//for (uint line = 6; line < 11; line++){

		for (uint x =0 ; x < ZEN_COLS; x++){
			uint8_t r = get_rand_32 () & 0xFF;
			if (r < xLines[line].onProb ){
				 uint8_t l = get_rand_32 () % xLines[line].maxLen;

				 if (
						 (line > ( ZEN_ROWS /4)) &&
						 (line < ( ZEN_ROWS -  ZEN_ROWS/4))
						 ){
					 if (
							 (x + l  > ( ZEN_ROWS /4)) &&
							 (x < ( ZEN_ROWS -  ZEN_ROWS/4))
							 ){
						 //Center region so do intensity check
						 r = get_rand_32 () & 0xFF;
						 if ( r > xIntensity){
							 continue;
						 }
					 }

				 }
				 //printf("Line %u  col %u Length is %u\n", line,  x, r);
				 uint32_t c = getColor();
				 drawLine(x, line, l, c);

				 x = x + l + 2 ;

				 r = get_rand_32 () & 0xFF;
				 if (r > xLines[line].mulProb){
					 x = x + 5;
					 //break;
				 }
			}
		}
	}

	pCanvas->show(alpha);

}

void ZenLamps::drawLine(uint x, uint y, uint length,  uint32_t  color){
	for (int i= 0; i < length; i++){
		pCanvas->setPixel(x+i,y,color);
	}
}

void ZenLamps::setIntensity(uint8_t i){
	xIntensity = i;
}

void ZenLamps::setSpeed(uint8_t i){
	xSpeed = i;
}

void ZenLamps::setColor(uint32_t color, uint32_t variance){
	xColor = color;
	xColorVar = variance;
}
