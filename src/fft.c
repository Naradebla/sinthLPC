/*
 * fft.c
 *
 *  Created on: 11 apr 2016
 *      Author: Gioele
 */
#include "fft.h"

void fft(short int in[],short int out[],modes mode){
	switch(mode){
		case points64:
			vF_dspl_fftR4b16N64(out,in);
			break;
		case points256:
			vF_dspl_fftR4b16N256(out,in);
			break;
		case points1024:
			vF_dspl_fftR4b16N1024(out,in);
			break;
		case points4096:
			vF_dspl_fftR4b16N4096(out,in);
			break;
	}
}
void ifft(short int in[],short int out[],modes mode){
	int i = 0;
	switch(mode){
			case points64:
				short int inverseIn[64*2];
				for(i = 0; i < (64*2); i++){
					inverseIn[i] = in[(64*2) -1 - i];
				}
				vF_dspl_fftR4b16N64(out,inverseIn);
				break;
			case points256:
				short int inverseIn[256*2];
				for(i = 0; i < (256*2); i++){
					inverseIn[i] = in[(256*2) -1 - i];
				}
				vF_dspl_fftR4b16N256(out,inverseIn);
				break;
			case points1024:
				short int inverseIn[1024*2];
				for(i = 0; i < (1024*2); i++){
					inverseIn[i] = in[(1024*2) -1 - i];
				}
				vF_dspl_fftR4b16N1024(out,inverseIn);
				break;
			case points4096:
				short int inverseIn[4096*2];
				for(i = 0; i < (4096*2); i++){
					inverseIn[i] = in[(4096*2) -1 - i];
				}
				vF_dspl_fftR4b16N4096(out,inverseIn);
				break;
		}

}
int getArrayLen(modes mode){
	switch(mode){
		case points64:
			return 64*2;
			break;
		case points256:
			return 256*2;
			break;
		case points1024:
			return 1024*2;
			break;
		case points4096:
			return 4096 *2;
			break;
	}
}
void rescaleArray (short int in[], short int out[], int inLen, modes mode){
	int targetIds = getArrayLen(mode);
	int reps = targetIds/(inLen*2);
	for(int i = 0; i < inLen;i++){
		for(int c = 0; c < reps; c++){
			if((c*inLen)+(i*2)>targetIds){
				break;
			}
			out[(c*inLen)+(i*2)] = in[i];
			out[(c*inLen)+((i*2)+1)] = 0;
		}
	}


}
