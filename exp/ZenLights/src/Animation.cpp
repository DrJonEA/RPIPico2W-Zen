/*
 * Animation.cpp
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#include "Animation.h"

Animation::Animation() {
	// TODO Auto-generated constructor stub

}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

void Animation::setCanvas(Canvas *p){
	pCanvas = p;
}


void Animation::reset(){
		xLast = 0;
}
