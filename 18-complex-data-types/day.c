#include <stdio.h>

enum Day{
    Monday=1,
    Tuesday=2,
    Wednesday=3,
    Thursday=4,
    Friday=5,
    Saturday=6,
    Sunday=7
};

int main(void){
    int n;
    printf("Enter number of a day\n");
    scanf("%d", &n);

    enum Day d=n;
    switch(d){
        case Monday: printf("Monday\n"); break;
        case Tuesday: printf("Tuesday\n"); break;
        case Wednesday: printf("Wednesday\n"); break;
        case Thursday: printf("Thursday\n"); break;
        case Friday: printf("Friday\n"); break;
        case Saturday: printf("Saturday\n"); break;
        case Sunday: printf("Sunday\n"); break;
        default: printf("a\n");
    }

    return 0;
}