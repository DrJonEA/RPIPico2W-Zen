/*
 * Animation.h
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#ifndef EXP_ANIMATIONS_SRC_ANIMATION_H_
#define EXP_ANIMATIONS_SRC_ANIMATION_H_

#include "pico/stdlib.h"
#include "Canvas.h"

class Animation {
public:
	Animation();
	virtual ~Animation();

	virtual void poll() = 0;
	virtual void reset();
	virtual void setCanvas(Canvas *p);


protected:

	Canvas *pCanvas=NULL;
	uint32_t xLast=0;
};

#endif /* EXP_ANIMATIONS_SRC_ANIMATION_H_ */
