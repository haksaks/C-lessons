#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n=0;
    do{
        printf("Enter count of school subjects\n");
        scanf("%d", &n);
    }while(n<1);

    char ** subjects=(char **)malloc(n*sizeof(char));
    for(int i=0; i<n; i++){
        char a=3;
        int k=0;
        //*subjects=NULL;
        printf("Enter subject\n");
        do{
            scanf("\n%c", &a);
            printf("%c", a);
            printf("%d\n", k);
            subjects[i]=(char *)realloc(subjects[i], k*sizeof(char));
            if(subjects[i]==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            subjects[i][k]=a;
            //printf("%c", a);
            printf("%c\n", subjects[i][k]);
            k++;
        }while(a!='\n' && k<15);
        printf("%c\n", subjects[i][k-1]);
        printf("%d\n", subjects[i][k-1]);
        if(subjects[i][k]=='\n'){
            subjects[i][k]='\0';
        }
        if(subjects[i]==NULL){
            printf("Error allocating memory\n");
            exit(1);
        }
        printf("%s\n", subjects[i]);
        printf("%d\n", subjects[i][k-1]);
    }

    char ** students=(char **)calloc(1, sizeof(char));
    int ** grades=(int **)calloc(1, sizeof(int));

    char option=0;
    int m=0;
    while(1){

        printf("'n' - add new student\n");
        printf("'p' - print all students and grades\n");
        printf("'e' - exit\n");

        scanf("\n%c", &option);
        /*m++;
        char ** students=(char **)realloc(students, m*sizeof(char));
        int k=0;
        char a=0;
        printf("Enter student\n");
        do{
            scanf("\n%c", &a);
            printf("%c", a);
            printf("%d\n", k);
            students[m-1]=(char *)realloc(students[m-1], k*sizeof(char));
            if(students[m-1]==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            students[m-1][k]=a;
            printf("%c", a);
            k++;
        }while(a!='\n' && k<15);
        if(students[m-1]==NULL){
            printf("Error allocating memory\n");
            exit(1);
        }
        printf("%s\n", students[m-1]);
        if(students[m-1][k-1]=='\n'){
            students[m][k-1]='\0';
        }*/
        if(option=='n'){

            m++;
            char ** students=(char **)realloc(students, m*sizeof(char));
            //students;

            int k=0;
            char a=0;
            printf("Enter student\n");
            do{
                scanf("\n%c", &a);
                printf("%c", a);
                printf("%d\n", k);
                students[m-1]=(char *)realloc(students[m-1], k*sizeof(char));
                if(students[m-1]==NULL){
                    printf("Error allocating memory\n");
                    exit(1);
                }
                students[m-1][k]=a;
                printf("%c", a);
                k++;
            }while(a!='\n' && k<15);
            if(students[m-1]==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            printf("%s\n", students[m-1]);
            if(students[m-1][k-1]=='\n'){
                students[m][k-1]='\0';
            }

            int ** grades=(int **)realloc(grades, m*sizeof(int));
            for(int i=0; i<m; i++){
                grades[i]=(int *)realloc(grades[i], n*sizeof(int *));
            }

            for(int i=0; i<n; i++){
                printf("Enter %s grade\n", subjects[i]);
                scanf("%d", &grades[m-1][i]);
            }
            for(int i=0; i<m; i++){
                printf("%p\n", students[i]);
            }
            if(students[m-1]==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }

        }else if(option=='p'){

            if(students[m-1]==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            printf("%d\n", m);
            printf("%p\n", students[m-1]);
            printf("                %s", subjects[0]);
            for(int i=1; i<n; i++){
                printf(" %s", subjects[i]);
            }
            printf("\n");
            for(int i=0; i<m; i++){
                printf("%s", students[i]);
                /*for(int j; j<n; j++){
                    printf("%d", grades[i][j]);
                }*/
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