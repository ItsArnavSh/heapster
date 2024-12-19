#include "util.h"
#include <stdio.h>
uint8_t noOfBits(uint16_t size){
    uint8_t bits = 0;
    while(size>0){
        bits++;
        size >>= 1;
    }
    return bits;
}
uint32_t getSize(void* loc){
    //We will get a location and have to return the size of that slot
    uint32_t num=0;
    uint8_t push = 0;
    uint8_t *data = --loc;//Starting of metadata
    num |= *data>>2;
    push = 5;
    while(*(--data)&1){
        num|=((*data&11111110)<<push);
        push+=6;
    }
    return num;
}
uint32_t totalBytes(uint32_t num){
    return ceil((double)(noOfBits(num)+1)/7);
}
uint32_t sizeCalc(uint32_t size){
    //This function receies a size and returns the size+metadata
    //k is one metadata, there will be two of those
    //So k stores the total bytes in the metadata
    //n = sizeNeeded + 2*k, as there is metadata at the back also
    for(uint8_t k=1;k<8;k++){
        uint32_t n = size+2*k;
        //If k and totalBytes(in meta) are equal, yay!
        if(k==totalBytes(n)){
            return n;
        }
    }
    return 0;
}
