/*
 * main.cpp
 * Drive  WB2812B on GP00
 *
 *      Author: jondurrant
 */


#include "pico/stdlib.h"

#include "Canvas.h"

#include "Animation.h"
#include "ZenLamps.h"


#define ANIM_TIME 10000


auto controller  = PicoLed::addLeds<PicoLed::WS2812B>(
		pio0,
		0,
		LEDS_PIN,
		LEDS_LENGTH,
		PicoLed::FORMAT_GRB);


int main(){

	stdio_init_all();

	controller.setBrightness(32);
	controller.fill( PicoLed::RGB(0x00, 0x00, 0xF0 ));
	controller.show();
	sleep_ms(2000);
	printf("Start\n");

    Canvas canvas(&controller);

	canvas.clear();
	ZenLamps zen(&canvas);
	for (;;){
		zen.poll();
		sleep_ms(20);
	}





}
