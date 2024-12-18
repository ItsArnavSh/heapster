#include "memStatus.h"
void* memory;
memFunc keys;

void* startAllocation(){
    //We start with 3 pages of memory
    void* memory = mmap(NULL,NEWMEM,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
    freeSlot s1 = {memory,NEWMEM};
    keys.slots[0] = s1;
    keys.size = 1;
    return memory;
}
void* bestMatch(uint8_t size){
    //We will just ierate through keys to find the best fit
    int bestMatch = 0;
    for(short i=1;i<keys.size;i++){
        if(keys.slots[i].size > bestMatch && keys.slots[i].size  >= size){
            bestMatch = i;
        }
        if(bestMatch==size){
            break;
        }
    }
    if(bestMatch<size){
        return startAllocation();

    }
    return keys.slots[bestMatch].start;
}
