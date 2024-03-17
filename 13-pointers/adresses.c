#include <stdio.h>

int main(void){
    double a, b;

    printf("a=?\n");
    scanf("%lf", &a);

    printf("b=?\n");
    scanf("%lf", &b);

    double *p1=&a;
    double *p2=&b;

    printf("%d\n", p1);
    printf("%d\n", p2);

    printf("%lf\n", *p1);
    printf("%lf\n", *p2);

    return 0;
}