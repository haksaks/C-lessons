#include <stdio.h>
#include "safeint.h"
#include <limits.h>

int main(int argc, char *argv[]){
    struct SafeResult a=safestrtoint(argv[1]);
    struct SafeResult b=safestrtoint(argv[2]);
    if(a.errorflag=='1'){
        printf("Error: argument a is too big for int type\n");
        return 1;
    }
    if(b.errorflag=='1'){
        printf("Error: argument b is too big for int type\n");
        return 1;
    }
    struct SafeResult c=safemultiply(a.value, b.value);
    if(c.errorflag=='1'){
        printf("Error: overflow\n");
    }else{
        printf("a * b = %d\n", c.value);
    }

    return 0;
}