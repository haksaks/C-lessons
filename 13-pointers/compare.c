#include <stdio.h>

int compareasc(const void *n, const void *m){
    const int *q1=n;
    const int *q2=m;
    if(*q1 > *q2){
        return 1;
    }else if(*q1 < *q2){
        return -1;
    }else{
        return 0;
    }
}

int comparedesc(const void *n, const void *m){
    const int *q1=n;
    const int *q2=m;
    if(*q1 < *q2){
        return 1;
    }else if(*q1 > *q2){
        return -1;
    }else{
        return 0;
    }
}

int main(void){
    const int a=22;
    const int b=15;

    const void *p1=&a;
    const void *p2=&b;

    printf("%d\n", compareasc(p1, p2));
    printf("%d\n", comparedesc(p1, p2));

    return 0;
}