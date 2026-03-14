/*
 * Arcs.h
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#ifndef EXP_ANIMATIONS_SRC_ARCS_H_
#define EXP_ANIMATIONS_SRC_ARCS_H_

#include "pico/stdlib.h"
#include "Animation.h"
#include "Ring.h"

#define ARCS_RINGS 8

class Arcs : public Animation {
public:
	Arcs(Canvas *p);
	virtual ~Arcs();

	virtual void poll();

private:
	Ring *pRings[ARCS_RINGS];
	float xRad = 0.0;
};

#endif /* EXP_ANIMATIONS_SRC_ARCS_H_ */
