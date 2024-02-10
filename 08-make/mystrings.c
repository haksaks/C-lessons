#include "mystrings.h"
#include <stdio.h>

int strlength(char str[]){
    int length=0;
    for(int i=0; str[i]!='\0'; i++){
        length++;
    }

    return length;
}

char * strconcat(char a[], char b[]){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    for(int j=0; b[j]!='\0'; j++, i++){
        a[i]=b[j];
    }
    a[i]='\0';

    return a;
}

int strcompare(char a[], char b[]){
    int result;
    int i=0;
    do{
        if(a[i]<b[i]){
            result=-1;
            break;
        }else if (a[i]==b[i]){
            if(a[i+1]=='\0' && b[i+1]!='\0'){
                result=-1;
            }else{
                result=0;
            }
        }else{
            result=1;
            break;
        }
        i++;
    }while(a[i]!='\0');

    return result;
}
