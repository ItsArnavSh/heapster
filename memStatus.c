#include "memStatus.h"
#include <limits.h>
#include <stdio.h>
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
    void* sol;
    //We will just ierate through keys to find the best fit
    int bestMatch = 0;
    for(short i=1;i<keys.size;i++){
        printf("Here2\n");
        if(keys.slots[i].size < keys.slots[bestMatch].size && keys.slots[i].size  >= size){
            bestMatch = i;
        }
        if(keys.slots[bestMatch].size==size){
            break;
        }
    }
    if(keys.slots[bestMatch].size<size){
        printf("Here\n");
        sol = startAllocation();
        keys.size++;
        bestMatch = 0;
    }
    sol =  keys.slots[bestMatch].start;

    //Now we have the sol, and its at index bestMatch
    keys.slots[bestMatch].start += size;
    keys.slots[bestMatch].size -= size;
    printf("Condition after allocation: size->%d\n",keys.slots[bestMatch].size);
    return sol;
}
void memPrinter(){
    for(int i=0;i<keys.size;i++){
        printf("Free Slot %d",keys.slots[i].size);
    }
}
