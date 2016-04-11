/*
 * dma.h
 *
 *  Created on: 08 apr 2016
 *      Author: Gioele
 */

#ifndef DMA_H_
#define DMA_H_

struct {
	unsigned int source;
	unsigned int destination;
	unsigned int next;
	unsigned int control;
} LLIO;

void repDMADAC(int* source,int len,int rate);
void pauseDMA();
void startDMA();

#endif /* DMA_H_ */
