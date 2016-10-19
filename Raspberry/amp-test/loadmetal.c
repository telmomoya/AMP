// 2016 Telmo Moya
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>



int main (int argc, char * argv [])
{
int fd_mem;
void *load_address;
unsigned long fileLen;
FILE *file;
printf ("Opening %s\n",argv[1]);
file=fopen(argv[1],"rb");

//Get file length
fseek(file, 0, SEEK_END);
fileLen=ftell(file);
fseek(file, 0, SEEK_SET);
printf ("File lenght %d\n",fileLen);

/* Map Physical address of RAM to virtual address segment with Read/Write Access */
printf ("Opening Mem %x\n",0x20000000);
fd_mem = open("/dev/mem", O_RDWR);
load_address = mmap(NULL, fileLen,PROT_READ|PROT_WRITE, MAP_SHARED, fd_mem, 0x20000000);

// Read file contents
  	fread(load_address, fileLen, 1, file);
	fclose(file);
}
