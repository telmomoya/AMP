// 2016 Telmo Moya

volatile char live=0x1;		//LCM flag
volatile char mailbox=0x20;	//Emulator OUT (Monitor)
volatile char mailbox2=0x0;	//Emulator IN(Keyboard)

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "6502/6502.h"
#include "io/gpios.h"


void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags )
{
reset6502();
while(live){
			step6502();
			}
}
