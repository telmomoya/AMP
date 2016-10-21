# Asymmetric Multi Processing (AMP) with Raspberry Pi

AMP for the masses
http://telmomoya.blogspot.com.ar/

In a multicore system Asymmetric Multi Processing (AMP) refers to heterogeneous cores, heterogeneous software for each core, or both. Raspberry Pi is a homogeneous multicore, so AMP is about heterogeneous software.

Particularly an AMP system was desirable to get a real time (deterministic) operation without losing the benefits of an OS:  bare-metal app running on one core and remainig cores running Linux.

Imagine the best of each world: Bare-metal speed and deterministic operation (with dedicated core/s) and Linux providing connectivity, security and plenty of drivers for easy peripheral access. And Inter Process Comunication(IPC) is the bridge between those worlds.


##History

Looking for a performance upgrade for my "ARM based 6510 ICE" I decided to use a Raspberry Pi bare metal app. I started reading excellent Brian's tutorials and making some tests. But SD card swaping between PC and RASPi did not suit me for a development process. Searching for a bootloader I found David's one and tested it with a homemade serial level adapter (using CH340 from a dead Arduino Nano board). That was a better development mechanism, but also tedious.

Thinking about a better option, AMP comes to my mind: If RasPi has 4 ARM cores why not use only one core for bare metal and remainings for development.

The idea was to boot Linux with Cores 0,1,2  and half RAM (lower 512Mb), leaving Core 3 and upper 512Mb for bare-metal. Compilation and linking will be done in Linux (no more cross compiling!) and a loader app (also Linux) will put the binary image in the upper memory used by bare-metal core. Then Core 3 must start the execution of that binary.

In my blog (http://telmomoya.blogspot.com.ar) you have simple instructions to obtain a working AMP system.


