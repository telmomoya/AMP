// 2016 Telmo Moya
/*
This file must be called with a parameter:
the hex physical address of the mailbox to monitor (show)
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h> 

#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

int main(int argc, char **argv) {

    char linea[255];

    int fd;
    void *map_base, *virt_addr; 
    unsigned long read_result, writeval, last_read;
    unsigned long  target;

    target = strtol(argv[1], NULL, 0);
    fd = open("/dev/mem", O_RDWR | O_SYNC);
//    printf("/dev/mem opened.\n"); 
    fflush(stdout);

    /* Map one page */
    map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
    //map_base == (void *);
//    printf("Memory mapped at address %p.\n", map_base); 
    printf("Sending line (char by char) to address 0x%X (%p):\n", target, virt_addr);

    fflush(stdout);
 
while (1)
    {
    fgets(linea,sizeof(linea),stdin);
    int i;
    for (i=0; i<strlen(linea); i++) {
        writeval = (int)(linea[i]);
        if (writeval==0x0a)writeval=0x0d;
        virt_addr = map_base + (target & MAP_MASK);
        *((unsigned char *) virt_addr) = writeval;
        usleep(500);
        }
    }

    fflush(stdout);
    munmap(map_base, MAP_SIZE);
    close(fd);
   return 0;
}

