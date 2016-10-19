#!/bin/sh
# 2016 Telmo Moya
# Call stop-metal (no arguments) and it will search the elf symbol table
# for the "live" global variable and make it 0
echo "Life cycle management control: Ending remoteproc"
lcm_control=0x$(nm up-metal-6510.elf | grep 'D live' | awk '{print $1}')
./devmem $lcm_control b 0x00
