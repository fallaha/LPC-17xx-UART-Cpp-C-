#include <LPC17XX.h>

class USART {
	
	public: 
	USART(void){
	LPC_SC->PCLKSEL0|=0X0;     //SET CLOCK OF UART0    CPUCLK/4=24MHZ
	LPC_UART0->LCR=0X83;      //SET 8bit data & enable dlab
	LPC_UART0->DLL=13;        // SET BAUD RATE = 115200
	LPC_UART0->DLM=0;
	LPC_UART0->LCR=0X3;      // DESABLE DLAB
	LPC_UART0->FCR=0X7;      // SET FIFO AND CLAER
	LPC_PINCON->PINSEL0=0X50;// SET PIN FOR UART
	}
	while (!(LPC_UART0->LSR & 1<<5));
	LPC_UART0->THR=ch;
	LPC_UART0->TER=0X80;

};


