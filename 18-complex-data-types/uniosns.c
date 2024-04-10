#include <stdio.h>

union Index{
    long odd;
    short even;
};

int main(void) {
    union Index arr[10];
    for(int i=0; i<10; i=i+2){
        arr[i].even=i;
    }

    for(int i=1; i<10; i=i+2){
        arr[i].odd=i;
    }

    for(int i=1; i<10; i=i+2){
        printf("%ld\n", arr[i].odd);
    }

    for(int i=0; i<10; i=i+2){
        printf("%hd\n", arr[i].even);
    }

  return 0;
}