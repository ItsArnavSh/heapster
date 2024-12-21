#include "free.h"
#include "util.h"
#include <sys/types.h>
void* createFreeA(void* memory,uint16_t size){
    void* mem = encode(memory, size, 1);
    return mem;
}
void release(void* mem){
    //So we get a memory, then we check to the left or right for merges
    //Check Next
    //Check Back
    //If no merges are needed, just change the status
    uint8_t *val = --mem;
    *val = (*val)|0b00000100;
}
