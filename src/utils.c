/*
 * utils.c
 *
 *  Created on: 29 mar 2016
 *      Author: Gioele
 */
#include "utils.h"
#include <string.h>
#include "registers.h"

void debugArray(int* val, int len){
	int array[len];
	int i = 0;
	for(i = 0; i < len;i++){
		array[i] = *val;
		val++;
	}

}
void generetaCSV(int* val, int len){
	char array[500];
	memset(&array[0],0,500);
	int i = 0;
	for(i = 0; i < len;i++){
		char str[15];
		memset(&str[0],0,15);
		itoa(i,str,10);
		strcat(array,str);
		strcat(array,",");
		itoa(*val,str,10);
		strcat(array,str);
		strcat(array,"\n");
		val++;
	}
	printf(array);

}
