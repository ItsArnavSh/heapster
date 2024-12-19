#include "util.h"
uint8_t noOfBits(uint16_t size){
    uint8_t bits = 0;
    while(size>0){
        bits++;
        size >>= 1;
    }
    return bits;
}
