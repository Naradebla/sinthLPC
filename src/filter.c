/*
 * filter.c
 *
 *  Created on: 07 apr 2016
 *      Author: Gioele
 */
#include "commons.h"
void createLowPass(double target[], int len, double cutOffFreq, double slopeFreq){
	double factor = SAMPLERATE/len;
	double cutOff = cutOffFreq/factor;
	double slope = (1000*slopeFreq/factor);
	double startF = ((slope*cutOff)-0.5)/slope;
	double endF = (1/slope)+startF;
	/*printf("Factor = %f\n",factor);
	printf("Normalized cutoff = %f\n",cutOff);
	printf("Normalized slope = %f\n",slope);
	printf("Start freq = %f\n",startF);
	printf("End freq = %f\n",endF);*/
	double i = 0;
	for(i = 0; i < len; i++){
		int h = i;
		if(i < startF){
			target[h] = 1;
			continue;
		}
		if(i > endF){
			target[h] = 0;
			continue;
		}
		target[h] = 1 - ((i - startF)*slope);
	}
}
void applyFilter(int in[], int out[],double filter[],int len){
	int i = 0;
	for(i = 0; i < (len/2); i++){
		out[i*2] = in[i*2] * filter[i];
		out[(i*2)+1] = in[(i*2)+1] * filter[i];
	}
}
