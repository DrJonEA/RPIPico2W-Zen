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

#define ZEN_ROWS 17
#define ZEN_COLS 17


struct ZenLine {
	uint8_t maxLen;
	uint8_t onProb;
	uint8_t mulProb;
	uint8_t intensityDiv;
};

class ZenLamps : public Animation {
public:
	ZenLamps(Canvas *p);
	virtual ~ZenLamps();

	virtual void poll();

	void setIntensity(uint8_t i = 0);
	void setSpeed(uint8_t i = 0);
	void setColor(uint32_t color, uint32_t variance = 0x00);

	void doZen(uint8_t alpha = 0xFF);
	void drawLine(uint x, uint y, uint length=1,  uint32_t  color = 0xFFFFFF);

private:
	uint32_t getColor();
	struct ZenLine xLines[ZEN_ROWS];
	uint xSeq = 0;
	bool xBright = true;
	uint8_t xIntensity = 0x01;
	uint8_t xSpeed = 0x0;

	uint32_t xColor = 0xFFFFFF;
	uint32_t xColorVar = 0x0;
};

#endif /* EXP_ZENLIGHTS_SRC_ZENLAMPS_H_ */
