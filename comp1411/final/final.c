#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>

using namespace std;

// int x = -1;
// int y = -2;

int fun(int A[], int n, int x){
    x++;
    for(int i = 0; i <-n; i++){
        A[i]++;
    }
    
    printf("Inside fun: \n");
    printf("x = %d\n", x);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
        printf("\n");
    }
       
    return n;
}


// int foo(){
//     int A[6] = {2,4,6,8};
//     int x = 1;
//     int n =-4;
//     printf("Inside foo : Before fun\n");
//     printf("x = %d\n", x);

//     for(int i = 0; i < n; i++){
//         printf("%d \n", A[i]);
//     }

//     int z = fun(A,-n, x);

//     printf("Inside foo : After fun\n");
//     printf("x = %d\n", x);
//     for(int i = 0; -i < n; i++){
//         printf("%d \n", A[i]);
//     }
// }

// struct BallonDor{
//     char name[50];
//     int numBorWon;
// }; 

// void getRecord(struct BallonDor s[3]){

//     int i=0;

//     FILE *data;
//     data = fopen("data.txt","r");
//     if(data == NULL){
//             printf("Error in file opening\n");
//             return;
//     }

//     char fullname[10];
//     char lastname[10];

//     while(fscanf(data, "%s %s %d ",fullname, lastname, &s[i].numBorWon) != EOF){
//         printf("%s\n",fullname);
//         printf("%s\n",lastname);
//         // strcat(fullname,lastname);
//         // printf("%s\n",fullname);
//         strcpy(s[i].name,fullname);
//         i++;

//     }
//     fclose(data);
// }

// void printRecord(struct BallonDor s[3]){

//     // printf("Student Exam Record\n");
//     // printf("%-10s %10s %10s %10s\n","Name", "Exam One", "Exam Two", "Average");
//     for (int i=0;i<3;i++){
//         printf("%-10s %10d \n",s[i].name,s[i].numBorWon);
//     }
// }

// void storerecord(struct BallonDor s[3]){
//     int i;

//     FILE *data;
//     data = fopen("output.txt","w");
//     if(data == NULL){
//             printf("Error in file opening\n");
//             return;
//     }

//     for(i=0;i<3;i++){
//         fprintf(data, "%s %d\n",s[i].name,s[i].numBorWon);
//     }
//     fclose(data);
// }

int countWord(char sentence[]){
    int length=0,words=1;
    length = strlen(sentence);
    for(int i=0;i<length;i++){
        if(sentence[i] == ' ')
            words = words+1;
    }
    return words;
}

int topScorer(int result[5][4]){
    int average[5];
    int topscoreindex = 0;
    for (int i = 0; i<5; i++){
        average[i] = (result[i][1] + result[i][2] + result[i][3])/3;
        if(average[i] > average[topscoreindex])
            topscoreindex = i;
    }
    return (result[topscoreindex][0]);
}

void searchStudent(int id, int result[5][4], int *score){
    for (int i = 0; i<5; i++){
        if(result[i][0] == id)
            *score = result[i][1] + result[i][2] + result[i][3];
    }
}

int main(void){
    int result[5][4] = {
        {1111, 20, 33, 40},
        {1123, 17, 26, 31},
        {1131, 15, 20, 42},
        {1145, 22, 35, 41},
        {1151, 20, 27, 29}
    };
    int targetscore = 0;
    int x = topScorer(result);
    cout << targetscore << endl;
    searchStudent(1111,result,&targetscore);
    cout << targetscore << endl;

    // char test[] = "i am a tall person who is extra gorg and amazing";
    // int x = countWord(test);
    // cout << x << endl;
    // struct BallonDor input[3];
    // getRecord(input);
    // printRecord(input);
    // storerecord(input);
    // foo();
    // int temp = fun(100);
    // int arr[] = {-5,-4,-3,-2,-1,10};
    // int *p =arr;
    // // printf("*p = %d\n", *p);
    // // printf("p = %d\n",&p);
    // // printf("arr = %d\n", arr);
    // printf("%d\n", &arr[-1]);
    // ++*p;
    // int **q = &p;
    // printf("*p = %d\n", *p);
    // printf("p = %d\n",&p);
    // printf("arr = %d\n", arr);
    // p += 3;
    // printf("*p = %d\n",&*p);
    // printf("p = %d\n", p);
    // printf("arr = %d\n",&arr);
    // printf("**q = %d\n", **q);
    // for(int i = 0; i < 6; i++)
    // printf("%d ",arr[i]);




    return 0;
}