#include <stdio.h>

int n=10;
int a[]={3, 5, 2, 8, 4, 10, 12, 7, 9, 11};

void bubblesort(int a[], int n, int (*compare)(void*, void*), void (*swapelements)(void*, void*)){
    int sorted=1;
    do{
        sorted=1;
        for(int i=0; i<n-1; i++){
            void *p1=&a[i];
            void *p2=&a[i+1];
            if((*compare)(p1, p2)>0){
                (*swapelements)(p1, p2);
                sorted=0;
            }
        }
    }while(!sorted);
}

int compare1(void *n, void *m){
    int *p1=n;
    int *p2=m;

    if(*p1>*p2){
        return 1;
    }else{
        return 0;
    }
}

void swapelements1(void *n, void *m){
    int *p1=n;
    int *p2=m;

    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int compareasc(void *n, void *m){
    int *q1=n;
    int *q2=m;
    if(*q1 > *q2){
        return 1;
    }else if(*q1 < *q2){
        return -1;
    }else{
        return 0;
    }
}

int comparedesc(void *n, void *m){
    int *q1=n;
    int *q2=m;
    if(*q1 < *q2){
        return 1;
    }else if(*q1 > *q2){
        return -1;
    }else{
        return 0;
    }
}

int main(void){

    int (*compare)(void*, void*)=compareasc;
    int (*compare1)(void*, void*)=comparedesc;
    void (*swapelements)(void*, void*)=swapelements1;

    bubblesort(a, n, compare, swapelements);
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    
    bubblesort(a, n, compare1, swapelements);
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}