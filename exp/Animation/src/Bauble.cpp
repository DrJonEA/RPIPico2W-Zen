/*
 * Bauble.cpp
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#include "Bauble.h"
#include "ColorUtils.h"

#define STEP_TIME 2000

Bauble::Bauble(Canvas *p) {
	setCanvas(p);

	//1+8+12+16+24+32+40+48+60
	int start = 0;
	int end =  60 ;

	pRings[0] = new Ring(
			new PicoLed::PicoLedController(
						*pCanvas->getController(),
						start,
						end
						),
			PicoLed::RGB(0xE5, 0, 0)
			);

	start = end;
	end = start + 48;
	pRings[1] = new Ring(
			new PicoLed::PicoLedController(
						*pCanvas->getController(),
						start,
						end
						),
			PicoLed::RGB(0xFF, 0x8D, 0),
			M_PI
			);

	start = end;
	end = start + 40 ;
	pRings[2] = new Ring(
				new PicoLed::PicoLedController(
							*pCanvas->getController(),
							start,
							end
							),
				PicoLed::RGB(0xFF, 0xEE, 0),
				M_PI/2.0
				);

	start = end;
	end = start + 32 ;
	pRings[3] = new Ring(
					new PicoLed::PicoLedController(
								*pCanvas->getController(),
								start,
								end
								),
					PicoLed::RGB(0x00, 0x81, 0x21),
					M_PI/-2.0
					);

	start = end;
	end = start + 24 ;
	pRings[4] = new Ring(
					new PicoLed::PicoLedController(
								*pCanvas->getController(),
								start,
								end
								),
					PicoLed::RGB(0x00, 0x4c, 0xFF),
					M_PI/4.0
					);

	start = end;
	end = start + 16 ;
	pRings[5] = new Ring(
					new PicoLed::PicoLedController(
								*pCanvas->getController(),
								start,
								end
								),
					PicoLed::RGB(0x76, 0x0, 0x88),
					M_PI/-4.0
					);

	start = end;
	end = start + 12 ;
	pRings[6] = new Ring(
					new PicoLed::PicoLedController(
								*pCanvas->getController(),
								start,
								end
								),
					PicoLed::RGB(0xF5, 0xAB, 0xB9),
					M_PI/3.0
					);

	start = end;
	end = start + 8 ;
	pRings[7] = new Ring(
					new PicoLed::PicoLedController(
								*pCanvas->getController(),
								start,
								end
								),
					PicoLed::RGB(0x5B, 0xCF, 0xFB),
					M_PI/-3.0
					);
}

Bauble::~Bauble() {
	// TODO Auto-generated destructor stub
}

void Bauble::poll(){
	uint32_t now = to_ms_since_boot (get_absolute_time());
	if ((xLast + STEP_TIME) > now){
		return;
	}
	xLast = now;

	uint8_t r,g,b;
	for (int i=0;  i<8; i++){
		ColorUtils::valToRGB(xColour + (0.02 * (float)i), r, g, b);
		pRings[i]->fill(r,g,b);
	}
	ColorUtils::valToRGB(xColour + 0.16, r, g, b);
	pCanvas->getController()->setPixelColor(LEDS_LENGTH-1, PicoLed::RGB(r,g,b));
	pCanvas->getController()->show();

	xColour += 0.1;
	if (xColour >= 1.0){
		xColour = 0.0;
	}
}

