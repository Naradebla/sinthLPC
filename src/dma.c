#include "dma.h"
#include "registers.h"
void repDMADAC(int* source,int len,int rate){
    //DMA Enable (No sync)
    DMACEnbldChns = 1; //Ch0 enambled
    DMACConfig = 1; //DMA enambled little-endian
    DMACSync = 1; //Ch0 sync disabled

    //DMA Linked list config
    LLIO.source = source;
    LLIO.destination = &DACR;
    LLIO.next = &LLIO;
    LLIO.control = len | (2 << 18) | (2 << 21) | (1 << 26);

    //DMA CH0 config
    DMACC0SrcAddr = source;
    DMACC0DestAddr = &DACR;
    DMACC0LLI = &LLIO;
    DMACC0Control = len | //Transfer size
    				(0 << 12) | //1 source busrt size (?)
					(0 << 15) | //1 destination busrt size (?)
					(0x2 << 18) | //Source width = 32 bit
					(0x2 << 21) | //Destination width = 32 bit
					(1 << 26) | //Source incremenet = 1
					(0 << 27)| //Destination incement = 0
					(0 << 31); //Terminal count interrupt disabled
    DMACC0Config = 1 |//Channel enambled
    				(0 << 1) | //Source periph 0 (memory)
					(7 << 6) | //Dest periph 7 (DAC)
					(1 << 11) | //Transfer type (memory to periph)
					(0 << 14) | // Error interrupt mask (Masked)
					(0 << 15) | // Terminal count interrupt mask (Maksed)
					(0 << 18); // No halt

    DACCTRL = (1 << 1)|(1 << 2)|(1 << 3);//Dobule buffering + Time-out counter + DMA access
    DACCNTVAL = rate;
    pauseDMA();
}
void pauseDMA(){

}
void startDMA(){

}

