#!/bin/sh
# 2016 Telmo Moya
gcc -O2 -c 6510.c -o 6510.o
gcc -O2 -c 6502/6502.c -o 6502/6502.o
gcc -O2 -c io/gpios.c -o io/gpios.o


gcc -O2 -c armc-08-start.S -o armc-08-start.o
# gcc -O2 -c armc-03.c -o armc-03.o


#ld -Ttext 0x20000000 -nostartfiles -T rpi.x armc-03.o armc-08-start.o 6510.o 6502/6502.o io/gpios.o -o up-metal-6510.elf


ld -Ttext 0x20000000 -nostartfiles -T rpi.x armc-08-start.o 6510.o 6502/6502.o io/gpios.o -o up-metal-6510.elf

objcopy up-metal-6510.elf -O binary up-metal-6510.img

