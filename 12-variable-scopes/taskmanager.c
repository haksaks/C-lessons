#include <stdio.h>
#include "processes.h"

int main(int argc, char *argv[]){
    char k;
    char a[30];
    int n;
    struct Process taskmanager[5];
    extern int processescount;

    while(1){
        printf("Choose option:\n");
        printf("'n' - create new process\n");
        printf("'p' - print all processes\n");
        printf("'s' - stop process\n");
        printf("'e' - Exit\n");

        scanf("\n%c", &k);
        if(k=='n'){
            if(processescount<5){
                scanf("\n%s", &a);
                taskmanager[processescount]=createnewprocess(a);
            }else{
                printf("The maximum amaount of processes is reached. Stop a working process to start a new one\n");
            }
        }else if(k=='p'){
            for(int i=0; i<processescount; i++){
                printf("%s %d\n", taskmanager[i].name, taskmanager[i].ID);
            }
        }else if(k=='s'){
            printf("Enter process Id\n");
            scanf("%d", &n);
            taskmanager[5]=stopprocess(n);
        }else if(k=='e'){
            break;
        }
    }
    
    return 0;
}