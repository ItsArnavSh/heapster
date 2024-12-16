//pagesize is the minimum space allocated using mmap
#include <stdio.h>
#include <unistd.h>
int main(){
    long page_size = sysconf(_SC_PAGESIZE);
        if (page_size == -1) {
            perror("sysconf");
            return 1;
        }

     printf("System page size: %ld bytes\n", page_size);
}
//4096 in my case
//So when I run mmap, the storage will always be a multiple of it...I guess...Ill test
