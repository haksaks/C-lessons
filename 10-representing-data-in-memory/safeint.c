#include <stdio.h>
#include "safeint.h"
#include <limits.h>

struct SafeResult result;

struct SafeResult safeadd(int a, int b){
    result.errorflag='0';
    if(a>0 && b>INT_MAX-a){
        result.errorflag='1';
    }else if(a<0 && b<INT_MIN-a){
        result.errorflag='1';
    }else{
        result.value=a+b;
        result.errorflag='0';
    }

    return result;
}

struct SafeResult safesubtract(int a, int b){
    if(b>0 && a<INT_MIN+b){
        result.errorflag='1';
    }else if(b<0 && a>INT_MAX+b){
        result.errorflag='1';
    }else{
        result.value=a-b;
        result.errorflag='0';
    }

    return result;
}

struct SafeResult safemultiply(int a, int b){
    if( (a>0 && b>0 && b>INT_MAX/a) || (a<0 && b<0 && b<INT_MAX/a) ){
        result.errorflag='1';
    }else if( (a>0 && b<0 && b<INT_MIN/a) || (a<0 && b>0 && b>INT_MIN/a) ){
        result.errorflag='1';
    }else{
        result.value=a*b;
    }

    return result;
}

struct SafeResult safedivide(int a, int b){
    if(b==0){
        result.value=0;
        result.errorflag='1';
    }else{
        result.value=a/b;
        result.errorflag='0';
    }

    return result;
}

struct SafeResult safestrtoint(char a[]){
    int p;
    int k=1;
    result.value=0;
    result.errorflag='0';
    for(int i=0; a[i]!='\0'; i++){
        if(a[i]=='-' && i==0){
            k=-1;
        }else if(a[i]>='0' && a[i]<='9'){
            result=safemultiply(result.value, 10);
            p=+a[i]-48;
            if(result.errorflag=='0'){
                result=safeadd(result.value, p);
            }else{
                result.value=0;
                result.errorflag='1';
                break;
            }
        }else{
            result.value=0;
            break;
        }
    }
    result=safemultiply(result.value, k);

    return result;
}