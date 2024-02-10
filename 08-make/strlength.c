#include <stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv){
    if(argc!=2){
        printf("Error: You must enter one string\n");
    }else{
        printf("length: %d\n", strlength(argv[1]));
    }

    return 0;
}