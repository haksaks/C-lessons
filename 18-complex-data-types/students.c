#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[15];
    int number;
    double averageGrade;
} StudentType;

int main(void){
    char option=0;
    StudentType * students=(StudentType *)calloc(1, sizeof(StudentType));
    int n=0;

    students[0].number=5;

    while(1){
        printf("add new student\n");
        printf("print all students\n");
        printf("quit\n");

        if(students==NULL){
            printf("Error allocating memory\n");
            exit(1);
        }
        if(n>0){
            StudentType * students=(StudentType *)realloc(students, (n+1)*sizeof(StudentType *));
            if(students==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
        }

        scanf("\n%c", &option);

        if(option=='n'){
            n++;
            int k=0;
            char a=0;
            printf("Enter student: ");
            getchar();
            do{
                a=getchar();
                if(students[n-1].name==NULL){
                    printf("Error allocating memory\n");
                    exit(1);
                }
                students[n-1].name[k]=a;
                if(students[n-1].name==NULL){
                    printf("Error allocating memory\n");
                    exit(1);
                }
                k++;
            }while(a!='\n' && k<15);
            if(students[n-1].name==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            if(students[n-1].name[k-1]=='\n'){
                students[n-1].name[k-1]='\0';
            }

            printf("Enter number\n");
            scanf("%d", &students[n-1].number);

            printf("Enter average grade\n");
            scanf("%lf", &students[n-1].averageGrade);

        }else if(option=='p'){
            if(n>0){
                for(int i=0; i<n; i++){
                    printf("Name: %s; Number: %d; Average Grade: %lf;\n", students[i].name, students[i].number, students[i].averageGrade);
                }
            }else{
                printf("There are no students\n");
            }
        }else if(option=='q'){
            free(students);
            break;
        }else{
            printf("Invalid option\n");
        }
    }
}