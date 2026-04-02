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
	uint length;
	uint32_t onProb;
	uint32_t lenProb;
	uint32_t mulProb;
};

class ZenLamps : public Animation {
public:
	ZenLamps(Canvas *p);
	virtual ~ZenLamps();

	virtual void poll();

	void setIntensity(uint8_t i = 0xFF); //0 is most intense

	void doZen(uint8_t alpha = 0xFF);
	void drawLine(uint x, uint y, uint length=1,  uint32_t  color = 0xFFFFFF);

private:
	struct ZenLine xLines[ZEN_ROWS];
	uint32_t xColor = 0;
	uint xSeq = 0;
	bool xBright = true;
	uint8_t xIntensity = 0xFF;
};

#endif /* EXP_ZENLIGHTS_SRC_ZENLAMPS_H_ */
