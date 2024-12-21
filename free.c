#include "free.h"
#include "debug.h"
#include "util.h"
#include <stdio.h>
#include <sys/types.h>
void* createFreeA(void* memory,uint16_t size){
    void* mem = encode(memory, size, 1);
    return mem;
}
void release(void* mem){
    chunkDetails current = getDetails(mem-totalBytes(decodeSize(mem)));//-decodeSize(mem)+1);
    //So we get a memory, then we check to the left or right for merges
    //Check Next
    chunkDetails dataNext = getDetails(mem+current.availableSize+current.metaSize+1);
    if(dataNext.status){//Means the next one is also free, So we can merge easy peasy
        createFreeA(mem-totalBytes(decodeSize(mem)), current.TotalSize+dataNext.TotalSize);
    }
    else{//Means only this one needs to be changed
    uint8_t *val = --mem;
    *val = (*val)|0b00000100;
    }
}
