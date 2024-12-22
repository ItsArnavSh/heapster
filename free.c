#include "free.h"
#include "debug.h"
#include "memory.h"
#include "util.h"
#include <stdio.h>
#include <sys/types.h>

void* createFreeA(void* memory,uint16_t size){
    void* mem = encode(memory, size, 1);
    return mem;
}
void release(void* mem){
    void* startMem = mem-totalBytes(decodeSize(mem));
    chunkDetails current = getDetails(startMem);//-decodeSize(mem)+1);
    //So we get a memory, then we check to the left or right for merges
    //Check Next
    chunkDetails dataNext = getDetails(mem+current.availableSize+current.metaSize+1);
    chunkDetails dataPrev;
    dataPrev.status = 0;
    if(memStart!=startMem){
        dataPrev = getDetailsBack(mem-totalBytes(decodeSize(mem))-2);
        //printf("\nHere is the dataPrev: ");
        //printDetails(dataPrev);
    }
    //printf("Previous One is: %s\n",(dataPrev.status?"Free":"Allocated"));

    if(dataNext.status || dataPrev.status){
    if(dataNext.status){//Means the next one is also free, So we can merge easy peasy
        createFreeA(mem-totalBytes(decodeSize(mem)), current.TotalSize+dataNext.TotalSize);
        current.TotalSize = current.TotalSize+dataNext.TotalSize;
        printf("Right Merge Performed\n");
    }
    if(dataPrev.status){//Means the next one is also free, So we can merge easy peasy
        createFreeA(mem-dataPrev.TotalSize-2, current.TotalSize+dataPrev.TotalSize);
        printf("TotalSize %d",current.TotalSize+dataPrev.TotalSize);
        printf("Left Merge Performed\n");
    }}
    else{//Means only this one needs to be changed
    printf("Mono Merge Performed\n");
    uint8_t *nstart = mem-totalBytes(decodeSize(mem));
    chunkDetails data = getDetails(nstart);
    encode(nstart, data.TotalSize, 1);

    }
}
