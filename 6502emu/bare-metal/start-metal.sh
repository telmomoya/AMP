#!/bin/sh
# 2016 Telmo Moya
# This file load a 0x2000000 (upper 512Mb) placed bin and
# point Core3 Mailbox3 to that address to start it's execution
echo "Life cycle management control: remoteproc init: stop, load & start"
./stop-metal.sh
./loadmetal up-metal-6510.img
./devmem 0x400000bc w 0x20000000

