/*
 * Bauble.h
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#ifndef EXP_ANIMATIONS_SRC_BAUBLE_H_
#define EXP_ANIMATIONS_SRC_BAUBLE_H_

#include "pico/stdlib.h"
#include "Animation.h"
#include "Ring.h"


#define ARCS_RINGS 8

class Bauble : public Animation {
public:
	Bauble(Canvas *p);
	virtual ~Bauble();

	virtual void poll();

private:
	Ring *pRings[ARCS_RINGS];
	float xColour = 0.0;
	uint32_t xLast=0;
};

#endif /* EXP_ANIMATIONS_SRC_BAUBLE_H_ */
