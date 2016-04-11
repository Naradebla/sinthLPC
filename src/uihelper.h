/*
 * uihelper.h
 *
 *  Created on: 08 apr 2016
 *      Author: Gioele
 */

#ifndef UIHELPER_H_
#define UIHELPER_H_

#define AC 1 << 9
#define BC 1 << 8

int ALeds[4];
int BLeds[4];

int currentA;
int currentB;
int currentF;


void initUI();
void updateView();
void buttonPress();
void QEIUpdate();

#endif /* UIHELPER_H_ */
