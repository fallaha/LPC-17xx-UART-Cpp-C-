//----------------------------------------------------------//
//												UART.cpp File 
//							C++ UART for LPC1768 (eca rev A)
//		Written By Ali Fallah (Kashan) at 95/06/22 (2016)
//----------------------------------------------------------//

#include <lpc17XX.h>
#include "UART.h"
#include "stdint.h"
#include "AF_define.h"

#define dUART LPC_UART0




void UART :: uart0_init(void)
	{
	//NVIC_EnableIRQ(UART0_IRQn);  // Enable Intrrupt fot IRQ
	LPC_SC->PCLKSEL0|=PCLK_UART0(0);     //SET CLOCK OF UART    CPUCLK/4=24MHZ
	LPC_SC->PCONP |= PCUART0;
	LPC_UART0->LCR=LCR_8bit|Enable_DLAB;      //SET 8bit data & enable dlab
	LPC_UART0->DLL=_dll;        // SET BAUD RATE = 115200
	LPC_UART0->DLM=0;
	LPC_UART0->LCR&=Disable_DLAB;      // DESABLE DLAB
	LPC_UART0->FCR=ENABLE_FIFO|RESET_RXFIFO|RESET_TXFIFO;      // SET FIFO AND CLAER
	LPC_PINCON->PINSEL0|=PINSEL0_TXD0|PINSEL0_RXD0;// SET PIN FOR UART0
	//LPC_UART0->IER=ENABLE_RBR_IRQ;
	}
	
	void UART :: uart1_init(void)
	{
	LPC_SC->PCLKSEL0|=PCLK_UART1(0);  												   //SET CLOCK OF UART    CPUCLK/4=24MHZ
	LPC_SC->PCONP |= PCUART1;
	LPC_UART1->LCR=LCR_8bit|Enable_DLAB;  									    //SET 8bit data & enable dlab
	LPC_UART1->DLL=_dll;        																	// SET BAUD RATE = 115200
	LPC_UART1->DLM=0;	
	LPC_UART1->LCR&=Disable_DLAB;      													// DESABLE DLAB
	LPC_UART1->FCR=ENABLE_FIFO|RESET_RXFIFO|RESET_TXFIFO;      // SET FIFO AND CLAER
	LPC_PINCON->PINSEL0|=PINSEL0_TXD1;						 // SET PIN FOR UART0
	LPC_PINCON->PINSEL0|=PINSEL1_RXD1;

	}
	void UART :: uart2_init(void)
	{
	LPC_SC->PCLKSEL0|=PCLK_UART2(0);  												   //SET CLOCK OF UART    CPUCLK/4=24MHZ
	LPC_SC->PCONP |= PCUART2;
	LPC_UART2->LCR=LCR_8bit|Enable_DLAB;  									    //SET 8bit data & enable dlab
	LPC_UART2->DLL=_dll;        																	// SET BAUD RATE = 115200
	LPC_UART2->DLM=0;	
	LPC_UART2->LCR&=Disable_DLAB;      													// DESABLE DLAB
	LPC_UART2->FCR=ENABLE_FIFO|RESET_RXFIFO|RESET_TXFIFO;      // SET FIFO AND CLAER
	LPC_PINCON->PINSEL0|=PINSEL0_TXD2|PINSEL0_RXD2;						 // SET PIN FOR UART0
	}
	void UART :: uart3_init(void)
	{
	LPC_SC->PCLKSEL0|=PCLK_UART3(0);  												   //SET CLOCK OF UART    CPUCLK/4=24MHZ
	LPC_SC->PCONP |= PCUART3;
	LPC_UART3->LCR=LCR_8bit|Enable_DLAB;  									    //SET 8bit data & enable dlab
	LPC_UART3->DLL=_dll;        																	// SET BAUD RATE = 115200
	LPC_UART3->DLM=0;	
	LPC_UART3->LCR&=Disable_DLAB;      													// DESABLE DLAB
	LPC_UART3->FCR=ENABLE_FIFO|RESET_RXFIFO|RESET_TXFIFO;      // SET FIFO AND CLAER
	LPC_PINCON->PINSEL0|=PINSEL0_TXD3|PINSEL0_RXD3;						 // SET PIN FOR UART0
	}
	



	void UART :: sendchar0 (unsigned char ch) // send char to Uart
{
	while (!(LPC_UART0->LSR & 1<<5));
	LPC_UART0->THR=ch;
	LPC_UART0->TER=0X80;
}

	void UART :: sendchar1 (unsigned char ch) // send char to Uart
{
	while (!(LPC_UART1->LSR & 1<<5));
	LPC_UART1->THR=ch;
	LPC_UART1->TER=0X80;
}

	void UART :: sendchar2 (unsigned char ch) // send char to Uart
{
	while (!(LPC_UART2->LSR & 1<<5));
	LPC_UART2->THR=ch;
	LPC_UART2->TER=0X80;
}

	void UART :: sendchar3 (unsigned char ch) // send char to Uart
{
	while (!(LPC_UART3->LSR & 1<<5));
	LPC_UART3->THR=ch;
	LPC_UART3->TER=0X80;
}


unsigned char UART :: getchar0 (void)  // Get Character from Uart
{
	while (!(LPC_UART0->LSR & 0X1));   // wait for get character (send char from computer)
	return LPC_UART0->RBR;   // return get char
}

unsigned char UART :: getchar1 (void)  // Get Character from Uart
{
	while (!(LPC_UART1->LSR & 0X1));   // wait for get character (send char from computer)
	return LPC_UART1->RBR;   // return get char
}

unsigned char UART :: getchar2 (void)  // Get Character from Uart
{
	while (!(LPC_UART2->LSR & 0X1));   // wait for get character (send char from computer)
	return LPC_UART2->RBR;   // return get char
}

unsigned char UART :: getchar3 (void)  // Get Character from Uart
{
	while (!(LPC_UART3->LSR & 0X1));   // wait for get character (send char from computer)
	return LPC_UART3->RBR;   // return get char
}








