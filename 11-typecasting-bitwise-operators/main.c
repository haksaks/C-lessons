#include <stdio.h>
#include "quadraticroots.h"
#include <math.h>

int main(void){
    double a=1;
    double b=5;
    double c=-24;
    struct QuadraticRootsResult x=findroots(a, b, c);
    if(x.norealroots=='1'){
        printf("No real roots\n");
    }else{
        printf("x1 = %lf\n", x.x1);
        printf("x2 = %lf\n", x.x2);
    }

    return 0;
}