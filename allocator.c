#include "allocator.h"
#include <stdio.h>
void* getMoreMemory(){

}
void* allocate(uint32_t bytes){
    //Okay, first we need to figure out how much memory we need to access
    void* match = bestMatch(bytes+1);//+1 so that we can include the metadata
    printf("%p",match);
    return match+1;
}
