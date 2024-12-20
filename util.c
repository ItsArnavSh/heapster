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
void* encode(void* loc,uint32_t totalSize,bool allocated){
    uint8_t metadataSize = totalBytes(totalSize);
    printf("MetaData Size is %d\n",metadataSize);
    uint8_t *val = loc;
    if(metadataSize==1){
        *val |= ((totalSize<<2));
        *val |= allocated<<1;
        *val &= 0b11111110;

    }
    else{
        while(1){
            *val = 0;
            *val |= 0b11111100&((totalSize<<2));
            totalSize >>= 6;
            if(totalSize){
                *val |= 0b11;//We will modify the starting and ending values accordingly
            }
            else{
                *val |= (allocated<<1) | 1;
                break;
            }

            val++;
        }
        //Now we just need to make the very first one's least significant bit 0 again
        val = loc;
        *val &= 0b11111110;
    }
    //Now we will copy it towards the end
    //The entire length is totalSize
    val = loc;
    for(uint8_t i=0;i<metadataSize;i++){
        printBinary(*(val+i));
    }
    for(uint8_t i=0;i<metadataSize;i++){
        *(val+totalSize-i-1)=*(val+i);
    }
    return loc+metadataSize;
}
uint32_t decodeSize(void* loc){
    uint8_t* val = --loc;
    uint32_t num = 0;
    do{
        num = num<<6;
        num |= (*val)>>2;
    }while(*(val--)&0b1);
    return num;
}
uint32_t getSize(void* loc){

    //We are given an address and we have to get the size of that chunk
    int num = 0;

    return num;
}
uint32_t totalBytes(uint32_t num){
    return ceil((double)(noOfBits(num))/6);
}
uint32_t sizeCalc(uint32_t size){
    //This function receies a size and returns the size+2*metadata
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
void printBinary(uint32_t num) {
    for (int i = 7; i >= 0; i--) { // Start from the most significant bit
        printf("%c", (num & (1U << i)) ? '1' : '0');
        if (i % 8 == 0 && i != 0) { // Add a space every 8 bits for readability
            printf(" ");
        }
    }
    printf("\n");
}
