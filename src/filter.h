/*
 * filter.h
 *
 *  Created on: 07 apr 2016
 *      Author: Gioele
 */

#ifndef FILTER_H_
#define FILTER_H_

void createLowPass(double target[], int len, double cutOffFreq, double slopeFreq);
void applyFilter(int in[], int out[],double filter[],int len);

#endif /* FILTER_H_ */
