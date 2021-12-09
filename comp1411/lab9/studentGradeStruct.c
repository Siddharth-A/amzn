//*****************************************************************************
//* Program Name: studentGradeStruct.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 03/12/2021
//*
//* Inputs: data.txt file which contains the following parameters
//* Record.name         - names of 6 students in file data.txt
//* Record.examOne      - score of the students in test 1 in data.txt
//* Record.examTwo      - score of the students in test 2 in data.txt
//*
//* Outputs:
//* none
//*
//* This program does the following:
//*     i. reads data.txt file and stores the data in Record struct
//*    ii. calculate the average grade of the student based on Record.examOne and Record.examTwo score and store in Record.avg
//*   iii. sort Record.name, Record.examOne and Record.examTwo arrays based on Record.avg in descending order
//*    iv. print the data processed on the terminal
//*     v. print the top scorer based on the highest average score
//*****************************************************************************

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char name[50];
    int examOne;
    int examTwo;
    double avg;
}Record;

/*
Purpose         : reads the name and scores from two tests for each student
                  and stores it in Record sd structure
Input           :    
                Record sd[6] which contains the following fields: name, examOne, examTwo and avg

Output/Returns  :
                none
*/
void getRecord(Record sd[6]){

    int i=0;

    FILE *data;
    data = fopen("data.txt","r");
    if(data == NULL){
            printf("Error in file opening\n");
            return;
    }

    while(fscanf(data, "%s %d %d",&sd[i].name,&sd[i].examOne,&sd[i].examTwo) != EOF){
        // printf( "%s %d %d\n", sd[i].name,sd[i].examOne,sd[i].examTwo);
        i++;
    }
    fclose(data);
}


/*
Purpose         : recieves Record.examOne and Record.examTwo and calculates the average score and store in Record.avg
Input           :    
                Record sd[6] which contains the following fields: name, examOne, examTwo and avg

Output/Returns  :
                none
*/
void calculateAverageGrade(Record sd[6]){

    for(int i=0;i<6;i++){
        sd[i].avg = (sd[i].examOne+sd[i].examTwo)/2;
    }
}


/*
Purpose         : recieves and sorts Record.name, Record.examOne and Record.examTwo by sorting Record.avg in descending order using bubble sort
Input           :    
                Record sd[6] which contains the following fields: name, examOne, examTwo and avg

Output/Returns  :
                none
*/
void sortRecord(Record sd[6]){

    int swapavg=0, swaptest1=0, swaptest2=0;
    char swapname[10];
    int size=6;

    for(int i=0; i<size-1; i++){
        for(int j=0;j<size-i-1;j++){
            if(sd[j].avg < sd[j+1].avg){

                swapavg = sd[j].avg;
                sd[j].avg = sd[j+1].avg;
                sd[j+1].avg = swapavg;

                swaptest1 = sd[j].examOne;
                sd[j].examOne = sd[j+1].examOne;
                sd[j+1].examOne = swaptest1;

                swaptest2 = sd[j].examTwo;
                sd[j].examTwo = sd[j+1].examTwo;
                sd[j+1].examTwo = swaptest2;

                // need string copy function for this
                strcpy(swapname,sd[j].name);
                strcpy(sd[j].name,sd[j+1].name);
                strcpy(sd[j+1].name,swapname);
            }
        }
    }
}


/*
Purpose         : displays the student names, grade scores and average score in descending order
Input           :    
                Record sd[6] which contains the following fields: name, examOne, examTwo and avg

Output/Returns  :
                none

*/
void printRecord(Record sd[6]){

    printf("Student Exam Record\n");
    printf("%-10s %10s %10s %10s\n","Name", "Exam One", "Exam Two", "Average");
    for (int i=0;i<6;i++){
        printf("%-10s %10d %10d %10.2f\n",sd[i].name,sd[i].examOne,sd[i].examTwo,sd[i].avg);
    }
}


/*
Purpose         : displays the top average scorer of both exams
Input           :    
                Record sd[6] which contains the following fields: name, examOne, examTwo and avg

Output/Returns  :
                none

*/
void displayTopScorer(Record sd[6]){

    int i = 0;
    float top_avg = sd[i].avg;
    bool status = true;
    printf("\nTop Scorer\n");

    while(status){
        printf("%s\n", sd[i].name);
        i++;

        // if more than 1 high scores
        if(top_avg == sd[i].avg){
            status = true;
        }
        else{
            status = false;
            return;
        }
    }
}

int main(void){
    Record studentData[6];

    getRecord(studentData);
    calculateAverageGrade(studentData);
    sortRecord(studentData);
    printRecord(studentData);
    displayTopScorer(studentData);

    return 0;
}