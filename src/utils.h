/*
 * utils.h
 *
 *  Created on: 29 mar 2016
 *      Author: Gioele
 */

#ifndef UTILS_H_
#define UTILS_H_
static inline int periodSample(double sRate,double freq){
	double samples = (1/freq)*sRate;
	return samples;
}
void debugArray(int* val, int len);
void generetaCSV(int*val, int len);


#endif /* UTILS_H_ */
