#include <stdio.h>

#include <stdlib.h>

int main(void){
    int n=0;
    do{
        printf("Enter count of school subjects\n");
        scanf("%d", &n);
        getchar();
    }while(n<1);

    char ** subjects=(char **)calloc(n, sizeof(char));
    if(subjects==NULL){
        printf("Error allocating memory\n");
        exit(1);
    }
    for(int i=0; i<n; i++){
        char a=3;
        int k=0;
        printf("Enter subject %d: ", i+1);
        do{
            a=getchar();
            subjects[i]=(char *)realloc(subjects[i], k*sizeof(char));
            if(subjects[i]==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            subjects[i][k]=a;
            k++;
        }while(a!='\n' && k<15);
        if(subjects[i][k-1]=='\n'){
            subjects[i][k-1]='\0';
        }
    }

    char ** students=(char **)calloc(1, sizeof(char));
    if(students==NULL){
        printf("Error allocating memory\n");
        exit(1);
    }
    int ** grades=(int **)calloc(1, sizeof(int));
    if(grades==NULL){
        printf("Error allocating memory\n");
        exit(1);
    }

    char option=0;
    int m=0;
    while(1){

        printf("\n---------------------------------------\n");
        printf("'n' - add new student\n");
        printf("'p' - print all students and grades\n");
        printf("'e' - exit\n");
        printf("---------------------------------------\n");

        scanf("\n%c", &option);
        getchar();
        if(m>0){
            char ** students=(char **)realloc(students, m*sizeof(char));
            if(students==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            int ** grades=(int **)realloc(grades, m*sizeof(int));
            if(grades==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
        }
        if(option=='n'){

            m++;
            int k=0;
            char a=0;
            printf("Enter student: ");
            do{
                a=getchar();
                students[m-1]=(char *)realloc(students[m-1], k*sizeof(char));
                if(students[m-1]==NULL){
                    printf("Error allocating memory\n");
                    exit(1);
                }
                students[m-1][k]=a;
                k++;
            }while(a!='\n' && k<15);
            if(students[m-1][k-1]=='\n'){
                students[m-1][k-1]='\0';
            }

            for(int i=0; i<m; i++){
                grades[i]=(int *)realloc(grades[i], n*sizeof(int *));
                if(grades[i]==NULL){
                    printf("Error allocating memory\n");
                    exit(1);
                }
            }

            for(int i=0; i<n; i++){
                do{
                    printf("Enter %s grade: ", subjects[i]);
                    scanf("%d", &grades[m-1][i]);
                    getchar();
                }while(grades[m-1][i]<2 || grades[m-1][i]>6);
            }

        }else if(option=='p'){
            
            printf("                %-15s", subjects[0]);
            for(int i=1; i<n; i++){
                printf(" %-15s", subjects[i]);
            }
            printf("\n");
            for(int i=0; i<m; i++){
                printf("%-15s", students[i]);
                for(int j=0; j<n; j++){
                    printf(" %-15d", grades[i][j]);
                }
                printf("\n");
            }

        }else if(option=='e'){

            for(int i=0; i<n; i++){
                free(subjects[i]);
            }
            free(subjects);
            for(int i=0; i<m; i++){
                free(students[i]);
            }
            free(students);
            for(int i=0; i<m; i++){
                free(grades[i]);
            }
            free(grades);
            break;

        }else{
            printf("Incorrect option\n");
        }

    }

    return 0;
}
