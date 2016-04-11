/*
 * oscillators.c
 *
 *  Created on: 29 mar 2016
 *      Author: Gioele
 */
#include "oscillators.h"
#include "utils.h"
#include <math.h>
#include <stdlib.h>

void sineWave(int sRate, int freq,int ampl,int** target){
	//sRate-> sample rate (sample/sec)
	//freq-> sine wave frequency (Hz)
	//ampl-> wave amplitude (V?)


	double tSample = periodSample(sRate,freq);
	*target = malloc(tSample * sizeof(int));
	int* currentT = *target;
	int i = 0;
	for(i = 0; i < tSample;i++){
		*currentT = ((ampl/2) * sin(2*3.1415*i/tSample))+(ampl/2);
		*currentT = *currentT << 6;
		currentT++;
	}
	//bus = data;
}
void trgWave(int sRate, int freq,int ampl,int** target){
	double tSample = periodSample(sRate,freq);
	*target = malloc(tSample * sizeof(int));
	int* currentT = *target;
	double delta = ampl/(tSample/2);
	int i = 0;
	for(i = 0; i < tSample;i++){
		if(i < tSample/2){
			*currentT = delta*i;
		}else{
			*currentT = ampl-(i-(tSample/2))*delta;
		}
		*currentT = *currentT << 6;
		currentT++;
	}
}
void squareWave(int sRate, int freq,int ampl,int** target){
	double tSample = periodSample(sRate,freq);
	*target = malloc(tSample * sizeof(int));
	int* currentT = *target;
	int i = 0;
	for(i = 0; i < tSample;i++){
		if(i < tSample/2){
			*currentT = 0;
		}else{
			*currentT = ampl;
		}
		*currentT = *currentT << 6;
		currentT++;
	}
}
void sawWave(int sRate, int freq,int ampl,int** target){
	double tSample = periodSample(sRate,freq);
	*target = malloc(tSample * sizeof(int));
	int* currentT = *target;
	double delta = ampl/tSample;
	int i = 0;
	for(i = 0; i < tSample;i++){
		*currentT = delta*i;
		*currentT = *currentT << 6;
		currentT++;
	}
}
