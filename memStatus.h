#ifndef MEM_H
#define MEM_H
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#define NEWMEM 12287
typedef struct freeSlot{
    void* start;
    uint16_t size;
}freeSlot;
//For now, lets just make it a heap
typedef struct memFunc{
    freeSlot slots[512];
    uint32_t size;
}memFunc;
void memAdd(int memory);
void memRemove();
extern memFunc keys;
//extern void* memory;
void* startAllocation();
void* bestMatch(uint8_t);
#endif
