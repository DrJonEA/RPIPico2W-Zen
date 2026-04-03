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
	xLines[0] = {17, 0x10808080, 1, 0x00000F00};
	xLines[1] = {17, 0xE0808080, 1, 0x00000F00};
	xLines[2] = {17, 0xE0808080, 1, 0x00000F00};
	xLines[3] = {17, 0xE0808080, 2, 0x00000F00};
	xLines[4] = {17, 0xE0808080, 2, 0x00000F00};
	xLines[5] = {17, 0xE0808080, 3, 0x00000F00};
	xLines[6] = {17, 0xE0808080, 5, 0x00000F00};
	xLines[7] = {17, 0xF0808080, 4, 0x000F0000};
	xLines[8] = {17, 0x80808080, 10, 0xF0000000};
	xLines[9] = {17, 0xE0808080, 4, 0x000F0000};
	xLines[10] = {17, 0xE0808080, 3, 0x00000F00};
	xLines[11] = {17, 0xE0808080, 3, 0x00000F00};
	xLines[12] = {17, 0xE0808080, 2, 0x00000F00};
	xLines[13] = {17, 0xE0808080, 2, 0x00000F00};
	xLines[14] = {17, 0xE0808080, 1, 0x00000F00};
	xLines[15] = {17, 0xE0808080, 1, 0x00000F00};
	xLines[16] = {17, 0x10808080, 1, 0x00000F00};
}

ZenLamps::~ZenLamps() {
	// TODO Auto-generated destructor stub
}

void ZenLamps::poll(){
	uint8_t alpha = 0x00;

	uint8_t steps = 0xFF - xIntensity;

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

void ZenLamps::doZen(uint8_t alpha){
	uint32_t c = 0xFFFFFF;

	pCanvas->clear();

	for (uint line = 0; line < ZEN_ROWS; line++){
	//for (uint line = 6; line < 11; line++){
		for (uint x =0 ; x < ZEN_COLS; x++){
			uint32_t r = get_rand_32 ();
			if (r > xLines[line].onProb){
				 r = get_rand_32 () % xLines[line].lenProb;
				 if ( (r) < xLines[line].length){
					 //printf("Line %u  col %u Length is %u\n", line,  x, r);
					 drawLine(x, line, r, c);

					 x = x + r + 2 ;

					 r = get_rand_32 ();
					 if (r > xLines[line].mulProb){
						 break;
					 }
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
