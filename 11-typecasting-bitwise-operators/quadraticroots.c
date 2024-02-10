#include "quadraticroots.h"
#include <math.h>
#include <stdio.h>

struct QuadraticRootsResult roots;

struct QuadraticRootsResult findroots(double a, double b, double c){
    double D=(b*b)-(4*a*c);
    printf("%lf\n", D);
    if(D>0){
        roots.x1=-b+sqrtl(D);
        printf("%lf\n", roots.x1);
        roots.x1=roots.x1/(a*2);
        roots.x2=-b-sqrtl(D);
        roots.x2=roots.x2/(a*2);
        roots.norealroots='0';
    }else{
        roots.norealroots='1';
    }

    return roots;
}