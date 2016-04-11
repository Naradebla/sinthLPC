/*
 * oscillators.h
 *
 *  Created on: 29 mar 2016
 *      Author: Gioele
 */

#ifndef OSCILLATORS_H_
#define OSCILLATORS_H_

#include "utils.h"
int* bus;

void sineWave(int sRate, int freq,int ampl,int** target);
void trgWave(int sRate, int freq,int ampl,int** target);
void squareWave(int sRate, int freq,int ampl,int** target);
void sawWave(int sRate, int freq,int ampl,int** target);

#endif /* OSCILLATORS_H_ */
