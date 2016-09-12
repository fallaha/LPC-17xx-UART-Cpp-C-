# LPC 17xx (1768) UART C++

## Introduction
hello all
this project written for easy to use of UART (0,1,2,3) for LPC 1768 and like LPC 1768 microcontroller.


in this PRJ i write some file and class that there are name and short description in blow.

|name        |       description|
| ------------- |:-------------:| -----:|
|AF_CPU.cpp   |   for Now : get cpu clock |
|AF_define.h   |  Define PCONP,PCLKSEL0, PINSEL(0,1,2,3,4,7,9) for easy to use|
|AF_string.h   |  for Now: convert int to asscii|
|stdint.h      |  Define some Typedef|
|UART.cpp      |  initialize UART(0,1,2,3) --more in blow|

  
nice. the Importent thing is UART.cpp File.

this file can initialize all UART with Special Baud Rate.



## Usage
for use class UART you should Follow below code

	UART name(Number of UART (e.g. 2) , Baud Rate (e.g. 115200) );
	name.sendchar('a');
	name.sendstring("Salam");
	char ch = name.getchar();
	


## Developed By
this was My Project that Write By me (ali fallah) in 13 sep 2016 (95/06/22).

i hope this my work can help you... :)

ForNOW...!

GoodBye...!

  
