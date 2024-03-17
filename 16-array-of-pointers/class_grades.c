#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n=0;
    do{
        printf("Enter count of school subjects\n");
        scanf("%d", &n);
    }while(n<1);

    char **subjects=NULL;
    for(int i=0; i<n; i++){
        char a=3;
        int k=0;
        //*subjects=NULL;
        printf("Enter subject\n");
        do{
            scanf("\n%c", &a);
            k++;
            printf("%d\n", k);
            *subjects[i]=(char )realloc(subjects[i], k*sizeof(char *));
            if(*subjects==NULL){
                printf("Error allocating memory\n");
                exit(1);
            }
            *subjects[i]=a;
            printf("%c", &a);
        }while(a!='\n' && k<15);
        if(*subjects[i]=='\n'){
            subjects[i][k]='\0';
        }
    }

    char **students=NULL;
    //students;
    int **grades=NULL;

    char option=0;
    while(1){

        printf("'n' - add new student\n");
        printf("'p' - print all students and grades\n");
        printf("'e' - exit\n");

        scanf("\n%c", &option);
        int m=0;
        if(option=='n'){

            int k=0;
            char a=0;
            printf("Enter student\n");
            do{
                scanf("\n%c", &a);
                k++;
                printf("%d\n", k);
                students[m]=(char *)realloc(students[m], k*sizeof(char *));
                if(students==NULL){
                    printf("Error allocating memory\n");
                    exit(1);
                }
                *students[m]=a;
                printf("%c", &a);
            }while(a!='\n' && k<15);
            if(*students[m]=='\n'){
                students[m][k]='\0';
            }
            m++;

            grades=(int **)realloc(grades, m*sizeof(int *));
            for(int i=0; i<m; i++){
                grades[i]=(int *)realloc(grades[i], n*sizeof(int));
            }

            for(int i=0; i<n; i++){
                printf("Enter %s grade\n", *subjects[i]);
                scanf("%d", &grades[m-1][i]);
            }

        }else if(option=='p'){

            printf("                %s", *subjects[0]);
            for(int i=1; i<n; i++){
                printf(" %s", *subjects[i]);
            }
            printf("\n");
            for(int i=0; i<m; i++){
                printf("%s", *students[i]);
                for(int j; j<n; j++){
                    printf(" %d", grades[i][j]);
                }
                printf("\n");
            }

        }else if(option=='e'){

            free(subjects);
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