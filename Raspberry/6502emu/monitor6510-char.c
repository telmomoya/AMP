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

#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

int main(int argc, char **argv) {
//printf(atol(argv[1]));
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
    printf("Values at address 0x%X (%p):", target, virt_addr);

    fflush(stdout);
 
while (1)
    {
    virt_addr = map_base + (target & MAP_MASK);
    read_result = *((unsigned char *) virt_addr);
    if (read_result != last_read)
          {
          printf("%c", (char*)read_result); 
          fflush(stdout);
          last_read = read_result;
          }
    }

    fflush(stdout);
    munmap(map_base, MAP_SIZE);
    close(fd);
   return 0;
}

