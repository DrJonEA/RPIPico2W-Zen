/*
 * Snowflakes.h
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#ifndef EXP_ANIMATIONS_SRC_SNOWFLAKES_H_
#define EXP_ANIMATIONS_SRC_SNOWFLAKES_H_

#include "pico/stdlib.h"
#include "Animation.h"

#define SNOWFLAKE_COLOURS 7

class Snowflakes : public Animation {
public:
	Snowflakes();
	Snowflakes(Canvas *p);
	virtual ~Snowflakes();

	virtual void poll();

private:
	uint8_t xColour=0;
	static uint32_t xColours[SNOWFLAKE_COLOURS];
};

#endif /* EXP_ANIMATIONS_SRC_SNOWFLAKES_H_ */
