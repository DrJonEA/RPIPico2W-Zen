/*
 * Canvas.cpp
 *
 *  Created on: 14 Nov 2025
 *      Author: jondurrant
 */

#include "Canvas.h"
#include <PicoLed.hpp>
#include "mapping.h"
#include <cstring>

Canvas::Canvas(PicoLed::PicoLedController * p) {
	pController = p;
}

Canvas::~Canvas() {
	// TODO Auto-generated destructor stub
}

uint8_t Canvas::getRows(){
	return FRAME_SIZE;
}
uint8_t Canvas::getColumns(){
	return FRAME_SIZE;
}

PicoLed::PicoLedController * Canvas::getController(){
	return pController;
}

void Canvas::show(){
	for (int i=0; i < LEDS_LENGTH; i++){
		uint8_t x =  CIRCLIE_MAPPING[i][0];
		uint8_t y =  CIRCLIE_MAPPING[i][1];

		uint32_t c = framebuffer[x][y];
		uint8_t b = c & 0xFF;
		uint8_t g = (c >> 8) & 0xFF;
		uint8_t r = (c  >> 16) & 0xFF;

		pController->setPixelColor( i,  PicoLed::RGB(r,g,b));
	}
	pController->show();
}
void Canvas::clear(uint32_t c){
	for (int i = 0; i < FRAME_SIZE; i++)
	        for (int j = 0; j < FRAME_SIZE; j++)
	        	framebuffer[i][j] = c;
}

void Canvas::hzLine(uint8_t y, uint32_t c){
	clear();
	for (int x=0; x < FRAME_SIZE; x++){
		framebuffer[x][y] = c;
	}
}
void Canvas::vtLine(uint8_t x, uint32_t c){
	clear();
	for (int y=0; y < FRAME_SIZE; y++){
		framebuffer[x][y] = c;
	}
}


void Canvas::drawImg(const uint32_t *img){
	memcpy(framebuffer, img, FRAME_SIZE*FRAME_SIZE*4);
}

void Canvas::setPixel(uint8_t x, uint8_t  y, uint32_t c ){
	framebuffer[x][y]=c;
}

PicoLed::PicoLedController Canvas::slice(uint start, uint end){
	return pController->slice(start, end);
}
