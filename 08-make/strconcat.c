#include <stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv){
    if(argc!=3){
        printf("Error: You must enter two strings\n");
    }else{
        if(strlength(argv[1])>50){
            printf("Error: String1 is too long. The strings can't have more than 50 symbols\n");
        }else if(strlength(argv[2])>50){
            printf("Error: String2 is too long. The strings can't have more than 50 symbols\n");
        }else{
            printf("%s\n", strconcat(argv[1], argv[2]));
        }
    }

    return 0;
}
