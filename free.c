#include "free.h"
#include "util.h"
#include <sys/types.h>
void createFreeA(void* memory,uint16_t size){
    //First we find the number of bits in given size, plan accordingly
    uint8_t bits = noOfBits(size);

    //First we make up the first bit for representation
    uint8_t first = (size & 0b111111)<<2;
    first |= 1;
    int temp[7];
    uint8_t tlen = 1;
    //Now we see if we need more
    size = size>>6;
    if(!size){
        first &= 0b01;
    }
    else{
        while(1){
            temp[tlen] = (size & 0b1111111)<<1;//Shift by 1, for the indicator
            size >>= 7;
            if(size){
                temp[tlen] |=0b1;//If there is more, mark last bit as 1
            }
            else {
                temp[tlen] &= 0;
                break;
            }
            tlen++;

        }
    }
    //Now we will lay down the
    uint8_t* memInt = (uint8_t*)memory;
    for(int i=0;i<=tlen;i++){
        memInt[tlen] = temp[tlen];
    memInt[tlen+1] = first;
    //Now we will leave the space for memory, as said


    }
}
void convertToFreeA(void* memory){
    //So We are given a memory and we have to

}
void convertToFreeB(void* memory,uint16_t size){

}
void convertToFreeC(void* memory,uint16_t size){

}
void convertToFreeD(void* memory,uint16_t size){

}
