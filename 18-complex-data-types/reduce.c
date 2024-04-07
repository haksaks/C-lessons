#include <stdio.h>

typedef unsigned long long ull

ull reduce(ull a[], ull size, ull (*ptr)(ull, ull), ull n){
    ull result=n;for(int i=0; i<size; i++){
        result=*ptr(result, a[i]);
    }

    retuturn result;
}

ull add(ull a, ull b){
    ull c=a+b;
    return c;
}

int main(void){

    ull arr[5]={1, 2, 3, 4, 5};
    ull s=5;
    ull n=1;
    

    return 0;
}