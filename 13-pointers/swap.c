#include <stdio.h>

void swap(void *n, void *m){
    int * p1 = n;
    int * p2 = m;

    int temp=*p1;
    *p1=*p2;
    *p2=temp;

}

int main(void){
    int a=2;
    int b=5;

    void *p1=&a;
    void *p2=&b;

    swap(p1, p2);

    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}