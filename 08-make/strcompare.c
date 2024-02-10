#include <stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv){
    if(argc!=3){
        printf("Error: You must enter two strings\n");
    }else{
        printf("%d\n", strcompare(argv[1], argv[2]));
    }

    return 0;
}