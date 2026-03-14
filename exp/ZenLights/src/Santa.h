/*
 * Santa.h
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#ifndef EXP_ANIMATIONS_SRC_SANTA_H_
#define EXP_ANIMATIONS_SRC_SANTA_H_

#include "pico/stdlib.h"
#include "Animation.h"

class Santa : public Animation {
public:
	Santa();
	Santa(Canvas *p);
	virtual ~Santa();

	virtual void poll();

private:
	static const uint32_t IMG[];
};

#endif /* EXP_ANIMATIONS_SRC_SANTA_H_ */
