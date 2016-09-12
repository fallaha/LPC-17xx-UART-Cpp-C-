//----------------------------------------------------------//
//											main.cpp File 
//						C++ File main LPC1768 & LPC 17xx
//			Written By Ali Fallah (Kashan) at 95/06/22 (2016)
//----------------------------------------------------------//

#include <lpc17xx.h>
#include ".\AF_LIB\UART.h"
#include ".\AF_LIB\AF_string.h"


int main(){
	
	SystemInit();
	char str[32];
		int a=313;
	itoa (a,10,str); // int to asccii
	
	UART uart2(2,9600);
	uart2.sendstring(str);
	
	uart2.sendstring("it is AF library");
	LPC_GPIO2->FIOPIN=uart2.getchar(); // set led
	
	while(1);
	

}





