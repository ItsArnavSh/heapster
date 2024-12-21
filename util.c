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
    uint32_t copy = totalSize;
    uint8_t metadataSize = totalBytes(totalSize);
    uint8_t *val = loc;
    *val = 0;
    switch(metadataSize){
    case 1:
        *val |= ((totalSize<<3));
        *val |= allocated<<2;
        break;
    case 2:
        //The last one should have 00 at the end
        *val |= 0b11111100&(totalSize<<2);
        *val |= 0b10;

        totalSize >>= 6;
        //The First one will have  1 at the end
        val = val+1;
        *val = 0;
        *val |= ((totalSize<<3));
        *val |= allocated<<2 | 0b01;


    break;
    case 3:
        //The last one should have 00 at the end
        *val |= 0b11111100&(totalSize<<2);
        *val |= 0b10;

        totalSize >>= 6;
        //The one in the middle
        ++val;
        *val |= 0b11111100&(totalSize<<2);
        totalSize >>= 6;
        * val |= 0b11;
        //The First one will have  1 at the end
        val++;
        *val = 0;
        *val |= ((totalSize<<3));
        *val |= allocated<<2 | 0b01;
    break;
    default:
    break;
    }

    val = loc;

    for(uint8_t i=0;i<metadataSize;i++){

        *(val+copy-i-1)=*(val+i);

    }
    val = loc;
    return loc+metadataSize;
}
uint32_t decodeSize(void* loc){
    uint8_t* val = --loc;
    uint32_t num = 0;
    if((0b00000011&*val)==0){

         num |= (*val)>>3;
    }
    else{
    do{
        if((*val&0b00000001) && !(*val&0b00000010)){
            num |= (*val)>>3;
        }
        else{

        num = num<<6;
        num |= (*val)>>2;
        }

    }while(*(val--)&0b1);}
    return num;
}
uint32_t getSize(void* loc){

    //We are given an address and we have to get the size of that chunk
    //First off, we have to reach the first point of address of this block
    uint8_t *iter = loc;
    //The First block is the only one where second LSB is 0
    if((*iter&0b00000011)==0){//Means a case of only a single byte
        return decodeSize(iter+1);//It will do the heavylifting!
    }
    iter++;//Now we go on to the second bit bot hint
    //If it ends with 11, means it is a 3 byte
    //If if ends with 01. means it is a 2 byte
    if(!(*iter&0b10)){
        //Means 2 byte
        return decodeSize(iter+1);
    }
    else{
        //Means 3 byte
        return decodeSize(iter+2);
    }

}
uint32_t totalBytes(uint32_t num){
    return ceil((double)(noOfBits(num)+1)/6);
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

chunkDetails getDetails(void* loc){
    chunkDetails data;
    //We are given an address and we have to get the size of that chunk
    //First off, we have to reach the first point of address of this block
    uint8_t *iter = loc;
    //The First block is the only one where second LSB is 0
    if((*iter&0b00000011)==0){//Means a case of only a single byte
        data.memStart = iter+1;
        data.TotalSize =  decodeSize(data.memStart);//It will do the heavylifting!
        data.metaSize = 1;
        data.availableSize = data.TotalSize-2;
        data.status = (*iter)&0b00000100;
    }
    else{
    iter++;//Now we go on to the second bit bot hint
    //If it ends with 11, means it is a 3 byte
    //If if ends with 01. means it is a 2 byte
    if(!(*iter&0b10)){
        //Means 2 byte
        data.memStart = iter+1;
        data.TotalSize =  decodeSize(data.memStart);
        data.metaSize = 2;
        data.availableSize = data.TotalSize-4;
        data.status = (*iter)&0b00000100;

    }
    else{
        //Means 3 byte
        data.memStart = iter+2;
        data.TotalSize = decodeSize(data.memStart);
        data.metaSize = 3;
        data.availableSize = data.TotalSize-6;
        data.status = *(iter+1)&0b00000100;
    }
    }
    return data;
}
