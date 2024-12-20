#include "main.h"
#include "util.h"
#include <stdlib.h>
int main(){
    int ml =12;
    for(;;ml++){
    printf("Encoding: %d\n",ml);
    void* a = malloc(ml);
    void* b = encode(a,ml,1);
    if(ml!=getSize(a)){
    printf("Size of a from start is: %d",getSize(a));
        break;
    }
    }
}
