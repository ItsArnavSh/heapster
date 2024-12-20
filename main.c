#include "main.h"
#include "util.h"
#include <stdlib.h>
int main(){
    for(int i=1;;i++){
    int ml = i;
    printf("Encoding: %d\n",ml);
    void* a = malloc(ml);
    a = encode(a,ml,i);
    printf("Decode Size = %d\n",decodeSize(a));
    if(decodeSize(a)!=i){
        break;
    }
    }
}
