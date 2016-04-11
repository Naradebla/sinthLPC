/*
 * fft.h
 *
 *  Created on: 11 apr 2016
 *      Author: Gioele
 */

#ifndef FFT_H_
#define FFT_H_

typedef enum {points64,points256,points1024,points4096}modes;

void rescaleArray (short int in[], short int out[], int inLen, modes mode);
void fft( short int in[], short int out[],modes mode);
void ifft(short int in[],short int out[],modes mode);

#endif /* FFT_H_ */
