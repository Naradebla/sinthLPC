/*
===============================================================================
 Name        : lpc1769.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/


#include <math.h>
#include <stdlib.h>
#include "cr_dsplib.h"


#include "board.h"
#include "commons.h"
#include "utils.h"
#include "oscillators.h"
#include "registers.h"
#include "uihelper.h"
#include "dma.h"


int s = 0;

int* samples;

int tSamples = 0;

unsigned int fft_in[2048];
unsigned int fft_out[2048];
unsigned int filtered_fft[2048];


void SysTick_Handler(void)
{

}


void EINT3_IRQHandler (void)
{

	buttonPress();
	IO0IntClr |= 1<<9|1<<8;					// cancella l'interrupt di P0.9 appena gestito
}
int main(void) {

    PINSEL1 |= 0x200000;

    tSamples = periodSample(SAMPLERATE,FREQ);
    sineWave(SAMPLERATE,FREQ,AMPLITUDE,&samples);
	#ifdef DEBUG
    debugArray(samples,tSamples);
    generetaCSV(samples,tSamples);
	#endif
    PCONP |= (1<<29); //GPDMA power
    repDMADAC(samples,tSamples,SYSTICK_VAL);
    initUI();

    IO0IntEnF |= 1<<9|1<<8;
    IPR5 |= 0x0F<<11;
    ISER0 |= 1<<21;

    //FFT Low pass test
    memset(fft_in,0,sizeof(fft_in));
    int i = 0;
    int c = 0;
    for(i = 0; i < 1024; i++){
    	if(i-(c*tSamples) > tSamples){
    	    c++;
    	}
        fft_in[i*2] = samples[i-(c*tSamples)];

    }
    vF_dspl_fftR4b16N1024(fft_out, fft_in);
    double filter[1024];
    createLowPass(filter, 1024, FILTERCUTOFF,FILTERSLOPE );
    applyFilter(fft_out, filtered_fft,filter,1024);



    // STRELOAD = SYSTICK_VAL;
    // STCTRL = 7;
    /*memset(fft_in,0,sizeof(fft_in));
    int i = 0;
    for(i = 0; i < 1024; i++){
    	fft_in[i*2] = data;
    }
    vF_dspl_fftR4b16N1024(fft_out, fft_in);
    for(i = 0; i < 512; i++){
    	a = fft_out[i*2];
    	b = fft_out[i*2+1];
    	spectrum[i] = sqrt((a*a)+(b*b));
    }*/
    while(1) {
    	__asm volatile ("wfi");
    }
    return 0 ;
}
