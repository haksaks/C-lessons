#include <stdio.h>

int main(int argv, char * argc[]){
    char a=2;
    char b=0;
    char k;
    int k1;

    while(1){
        printf("Choose command\n");
        printf("'s' - switch lights\n");
        printf("'p' - print state\n");
        printf("'e' - exit\n");

        scanf("\n%c", & k);
        //printf("%c\n", k);

        if(k=='s'){
            printf("Enter room number\n");
            scanf("%d", & k1);
            if(k1>=1 && k1<=8){
                b=1<<(k1-1);
                a=a^b;
            } 
        }else if(k=='p'){
            printf("The light is on in rooms: ");
            for(int i=0; i<8; i++){
                if(a>>i & 1){
                    printf("%d ", i+1);
                }
            }
            printf("\n");
        }else if(k=='e'){break;}
        k='\0';
    }

    return 0;
}