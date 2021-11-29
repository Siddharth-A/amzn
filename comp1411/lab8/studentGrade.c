//*****************************************************************************
//* Program Name: studentGrade.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 25/11/2021
//*
//* Inputs: data.txt file which contains the following parameters
//* name[][]     - names of 6 students which are stored in the 2D array: name
//* test1[]      - score of the students in test 1 which are stored in 1D array: test1
//* test2[]      - score of the students in test 2 which are stored in 1D array: test2
//*           
//* Outputs: 
//* none
//*
//* This program does the following:
//*     i. reads data.txt file and stores the data in 3 arrays: name[][], test1[] and test2[]
//*    ii. calculate the average grade of the student based on test1 and test2 score and store in average[]
//*   iii. sort name, test1 and test2 arrays based on average array in descending order
//*    iv. print the data processed on the terminal
//*     v. print the top scorer based on the highest average score
//*****************************************************************************

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
Purpose         : reads the name and scores from two tests for each student 
                  and store names in char array and grades in double array
Input           :    
                name array:  char array of all student names
                test1 array: int array of student's score in test1
                test2 array: int array of student's score in test2

Output/Returns  :
                none
*/
void getRecord(char name[][10], int *test1, int *test2){

    int i=0;
    
    FILE *data;
    data = fopen("data.txt","r");
    if(data == NULL){
            printf("Error in file opening\n");
            return;
    }

    while(fscanf(data, "%s %d %d",name[i],&test1[i],&test2[i]) != EOF){
        i++;
    }
    fclose(data);
}


/*
Purpose         : recieves the two grade arrays and calculates the average score and store in array
Input           :    
                test1 array: int array of student's score in test1
                test2 array: int array of student's score in test2
                average array: float array of the avg score of student based on test1 and test2

Output/Returns  :
                none
*/
void calculateAverageGrade(int *test1, int *test2, float *average){
    
    for(int i=0;i<6;i++){
        average[i] = (test1[i]+test2[i])/2;
    }
}


/*
Purpose         : recieves and sorts test1,test2 and name array by sorting average array in descending order using bubble sort
Input           :
                name array:  char array of all student names    
                test1 array: int array of student's score in test1
                test2 array: int array of student's score in test2
                average array: float array of the avg score of student based on test1 and test2

Output/Returns  :
                none
*/
void sortRecord(char name[][10], int *test1, int *test2, float *average){
    
    int swapavg=0, swaptest1=0, swaptest2=0;
    char swapname[10];
    int size=6;

    for(int i=0; i<size-1; i++){
        for(int j=0;j<size-i-1;j++){
            if(average[j] < average[j+1]){
                
                swapavg = average[j];
                average[j] = average[j+1];
                average[j+1] = swapavg;

                swaptest1 = test1[j];
                test1[j] = test1[j+1];
                test1[j+1] = swaptest1;

                swaptest2 = test2[j];
                test2[j] = test2[j+1];
                test2[j+1] = swaptest2;

                // need string copy function for this
                // swapname = name[j];
                strcpy(swapname,name[j]);
                // *name[j] = *name[j+1];
                strcpy(name[j],name[j+1]);
                // name[j+1] = swapname;
                strcpy(name[j+1],swapname);
            }
        }
    }
}


/*
Purpose         : displays the student names, grade scores and average score in descending order
Input           :
                name array:  char array of all student names    
                test1 array: int array of student's score in test1
                test2 array: int array of student's score in test2
                average array: float array of the avg score of student based on test1 and test2

Output/Returns  :
                none
*/
void printRecord(char name[][10], int *test1, int *test2, float *average){

    printf("Student Exam Record\n");
    printf("%-10s %10s %10s %10s\n","Name", "Exam One", "Exam Two", "Average");
    for (int i=0;i<6;i++){
        printf("%-10s %10d %10d %10.2f\n",name[i],test1[i],test2[i],average[i]);
    }
}


/*
Purpose         : displays the top average scorer of both exams
Input           :
                name array:  char array of all student names    
                average array: float array of the avg score of student based on test1 and test2

Output/Returns  :
                none
*/
void displayTopScorer(char name[][10], float *average){
    
    int i = 0;
    float top_avg = average[i];
    bool status = true;
    printf("\nTop Scorer\n");

    while(status){
        printf("%s\n", name[i]);
        i++;

        // if more than 1 high scores
        if(top_avg == average[i]){
            status = true;
        }
        else{
            status = false;
            return;
        }
    }
}

int main(void){
    int test1[6];
    int test2[6];
    char name[6][10];
    float average[6];

    getRecord(name,test1,test2);
    calculateAverageGrade(test1,test2,average);    
    sortRecord(name,test1,test2,average);
    printRecord(name,test1,test2,average);
    displayTopScorer(name,average);

    return 0;
}