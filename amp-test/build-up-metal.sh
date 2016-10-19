#!/bin/sh
# 2016 Telmo Moya
gcc -O2 -c armc-03.c -o armc-03.o
gcc -O2 -c armc-08-start.S -o armc-08-start.o
gcc -O2 -c armc-08-cstartup.c -o armc-08-cstartup.o

ld -Ttext 0x20000000 -nostartfile -T rpi.x armc-03.o armc-08-cstartup.o armc-08-start.o -o up-metal.elf
objcopy up-metal.elf -O binary up-metal.img  

