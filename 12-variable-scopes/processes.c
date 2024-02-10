#include "processes.h"

struct Process processes[5];

int processescount=0;

int nextprocessid(){
    static int id=0;
    if(id<9){
        id++;
    }

    return id;
}

struct Process createnewprocess(char a[]){
    if(processescount<5){
        for(int i=0; i<30 && a[i]!='\0'; i++){
            processes[processescount].name[i]=a[i];
        }
        processes[processescount].ID=nextprocessid();
        if(processes[processescount].ID!=0){
            processescount++;
        }
    }

    return processes[processescount];
}

struct Process stopprocess(int n){
    for(int i=0; i<processescount; i++){
        if(processes[i].ID==n){
            for(i=i; i<processescount-1; i++){
                for(int j=0; processes[i+1].name[j]!='\0'; j++){
                    processes[i].name[j]=processes[i+1].name[j];
                }
                processes[i].ID=processes[i+1].ID;
            }
            for(int j=0; j<30; j++){
                processes[i].name[j]='\0';
            }
            processes[i].ID=0;
            processescount--;
            break;
        }
    }

    return processes[processescount];
}