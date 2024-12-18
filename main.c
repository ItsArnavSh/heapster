#include"allocator.h"
#include "memStatus.h"
#include <stdio.h>
int main() {
    void *a = allocate(5);

    void *b = allocate(1);

    printf("\nValue of %d %d\n",a,b);

}
