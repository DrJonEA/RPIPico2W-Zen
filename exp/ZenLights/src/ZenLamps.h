/*
 * ZenLamps.h
 *
 *  Created on: 14 Mar 2026
 *      Author: jondurrant
 */

#ifndef EXP_ZENLIGHTS_SRC_ZENLAMPS_H_
#define EXP_ZENLIGHTS_SRC_ZENLAMPS_H_

#include "pico/stdlib.h"
#include "Animation.h"

#define LAMP_COUNT 14


struct ZenLamp {
	uint x ;
	uint y;
	uint len;
	uint8_t priority;
};

class ZenLamps : public Animation {
public:
	ZenLamps(Canvas *p);
	virtual ~ZenLamps();

	virtual void poll();

private:
	struct ZenLamp xLamps[LAMP_COUNT];
	uint32_t xColor = 0;
	uint xSeq = 0;
	bool xBright = true;
};

#endif /* EXP_ZENLIGHTS_SRC_ZENLAMPS_H_ */
