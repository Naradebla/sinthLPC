/*
 * uihelper.c
 *
 *  Created on: 08 apr 2016
 *      Author: Gioele
 */
#include "uihelper.h"
#include "registers.h"

void updateView(){
	FIO0CLR = ALeds[0]|ALeds[1]|ALeds[2]|ALeds[3];
	FIO0CLR = BLeds[0]|BLeds[1]|BLeds[2]|BLeds[3];
	FIO2CLR = 0xFF;

	FIO0SET = ALeds[currentA];
	FIO0SET = BLeds[currentB];
	FIO2SET = (1 << ((7*currentF)/100));
}
void buttonPress(){
	if(IO0IntStatF&AC){
			currentA++;
			if(currentA > 3){
				currentA = 0;
			}
		}else if(IO0IntStatF&BC){
			currentB++;
			if(currentB > 3){
				currentB = 0;
			}
	}
	updateView();
}
void initUI(){
	ALeds[0] = 1 << 4;
	ALeds[1] = 1 << 5;
	ALeds[2] = 1 << 10;
	ALeds[3] = 1 << 11;

	BLeds[0] = 1 << 7;
	BLeds[1] = 1 << 6;
	BLeds[2] = 1 << 0;
	BLeds[3] = 1 << 1;

	currentA = 0;
	currentB = 0;
	currentF = 50;

	FIO0DIR |= ALeds[0]|ALeds[1]|ALeds[2]|ALeds[3]|BLeds[0]|BLeds[1]|BLeds[2]|BLeds[3];
	FIO2DIR |= 0xFF;
	updateView();
}
void QEIUpdate(){

}
