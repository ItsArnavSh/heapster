#include "allocate.h"
#include "memory.h"
#include "util.h"
void* alloc(uint16_t size){
    uint8_t *iter = memStart;
    uint16_t totalSize = sizeCalc(size);
    chunkDetails data = getDetails(iter);
    while(!data.status && data.availableSize<totalSize){
        iter = iter+data.TotalSize+1;
        data = getDetails(iter);
    }
    return shrink(totalSize,iter,data);
}
void* shrink(uint16_t totalSize,void* mem,chunkDetails data){
    //We will shrink the given memory now
    void* memStart = encode(mem,totalSize,0);
    //Now for the remaining memory in the block
    //Now we need to work towards setting up the freed memory
    encode(mem+totalSize,data.TotalSize-totalSize,1);
    return memStart;
}
