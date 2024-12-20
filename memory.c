#include "memory.h"
#include "free.h"
void * memStart  = NULL;
void* freeStart = NULL;
 void* buckets[9];
void startUP(){
    //FIrst we  set everything up
    for(uint8_t i = 0;i<9;i++)
        buckets[i] = NULL;
    //Now we will request for memory from mmap
    memStart = mmap(NULL,ALLOCSIZE,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
    uint8_t *loc = memStart+ALLOCSIZE+1;
    *loc = 0b11111111;
    void** pointer = createFreeA(memStart, ALLOCSIZE);
    freeStart = *pointer;
    *(++pointer) = NULL;
}
