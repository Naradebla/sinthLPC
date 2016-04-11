/*
 * common.h
 *
 *  Created on: 08 apr 2016
 *      Author: Gioele
 */

#ifndef COMMONS_H_
#define COMMONS_H_

#define DEBUG


#define CORE_CLK 96000000

#define FREQ 880
#define SAMPLERATE 1000000
//0x325
#define AMPLITUDE 0x325
#define SYSTICK_VAL CORE_CLK/(SAMPLERATE * 4)

#define FILTERCUTOFF 1000
#define FILTERSLOPE 0.2


#endif /* COMMONS_H_ */
