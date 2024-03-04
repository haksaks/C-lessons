#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    do{
        printf("Enter count of the student's grades\n");
        scanf("%d", &n);
    }while(n<0);

    size_t a=sizeof(float)*n;
    float *grades=(float *)malloc(a);
    if(grades==NULL){
        return 1;
    }else{

        for(int i=0; i<n; i++){
            printf("Enter grade\n");
            scanf("%f", &grades[i]);
        }

        char option;
        while(1){
            printf("Show average grade - 'a'\n");
            printf("Add new grade - 'g'\n");
            printf("Remove the last grade - 'r'\n");
            printf("Exit - 'e'\n");

            scanf("\n%c", &option);
            //printf("%c\n", option);

            if(option=='a'){
                if(n>0){
                    double averageGrade=0;
                    for(int i=0; i<n; i++){
                        averageGrade=averageGrade+grades[i];
                    }
                    averageGrade=averageGrade/n;
                    printf("Average grade - %2.2lf\n", averageGrade);
                }else{
                    printf("There are no grades\n");
                }
            }else if(option=='n'){
                if(n>0){
                    n++;

                    size_t b=sizeof(float)*n;
                    grades=(float *)realloc(grades, b);
                    if(grades==NULL){
                        return 1;
                        break;
                    }

                    printf("Enter grade\n");
                    scanf("%f", &grades[n-1]);
                }else{
                    n++;
                    size_t b=sizeof(float)*n;
                    float *grades=(float *)malloc(b);
                    if(grades==NULL){
                        return 1;
                        break;
                    }
                    printf("Enter grade\n");
                    scanf("%f", &grades[n-1]);
                }
            }else if(option=='r'){
                if(n>1){
                    n--;
                    
                    size_t b=sizeof(float)*n;
                    grades=(float *)realloc(grades, b);
                    if(grades==NULL){
                        return 1;
                        break;
                    }
                }else if(n==1){
                    n--;
                    free(grades);
                }else{
                    printf("All grades are aldeady deleted\n");
                }
            }else if(option=='e'){
                if(n>0){
                    free(grades);
                }
                break;
            }else{
                printf("Incorrect option\n");
            }
        }
    }

    return 0;
}