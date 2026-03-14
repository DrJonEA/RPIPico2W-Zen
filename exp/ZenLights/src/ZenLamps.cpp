/*
 * ZenLamps.cpp
 *
 *  Created on: 14 Mar 2026
 *      Author: jondurrant
 */

#include "ZenLamps.h"

ZenLamps::ZenLamps(Canvas *p) {
	setCanvas(p);
	xLamps[0] = {2, 8, 10, 0};
	xLamps[1] = {4, 6, 3, 1};
	xLamps[2] = {3, 10, 3, 1};
	xLamps[3] = {13, 6, 3, 1};
	xLamps[4] = {11, 10, 3, 1};

	xLamps[5] = {7, 1, 2, 3};
	xLamps[6] = {9, 3, 3, 3};
	xLamps[7] = {3, 4, 3, 2};
	xLamps[8] = {6, 12, 3, 2};
	xLamps[9] = {8, 6, 3, 1};

	xLamps[10] = {10, 12, 3, 2};
	xLamps[11] = {5, 14, 3, 3};
	xLamps[12] = {9, 16, 2, 3};
	xLamps[13] = {2, 12, 4, 2};


}

ZenLamps::~ZenLamps() {
	// TODO Auto-generated destructor stub
}

void ZenLamps::poll(){
	uint32_t c;
	for (int i=0; i < LAMP_COUNT; i++){
		switch(xLamps[i].priority){
		case 0:
			c = 0x010101 * xSeq;
			break;
		case 1:
			if (xSeq > 10){
				c = 0x000001 * xSeq;
				c += 0x010100 * (xSeq /2);
			} else {
				c = 0;
			}
			break;
		case 2:
			if (xSeq > 25){
				c = 0x00100 * xSeq;
				c += 0x010001 * (xSeq /2);
			} else {
				c = 0;
			}
			break;
		default:
			if (xSeq > 50){
				c = 0x010000 * (xSeq-30);
				c += 0x010100 * (xSeq /3);
			} else {
				c = 0;
			}
		}
		for (int x = 0; x < xLamps[i].len; x++){
			pCanvas->setPixel(
					xLamps[i].x + x,
					xLamps[i].y,
					c);
		}
	}
	pCanvas->show();
	if (xBright){
		if (xSeq >= 100){
			xBright = false;
		} else {
			xSeq++;
		}
	} else {
		if (xSeq == 0){
			xBright = true;
		} else {
			xSeq--;
		}
	}

}
