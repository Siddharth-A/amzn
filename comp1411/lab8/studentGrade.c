//*****************************************************************************
//* Program Name: name_extract.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 27/11/2021
//*
//* Inputs: 
//* email[200]     - input array used to store the email ID entered by user
//* user           - users input to the question "Try again[Y/N]"
//*           
//* Outputs: 
//* none
//*
//* This program does the following:
//*     i. asks user to enter an email ID
//*    ii. splits the ID into first name and last name based on char:- "."
//*   iii. capitalizes the first and last name and prints it
//*****************************************************************************

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Purpose         : reads the name and scores from two tests for each student 
                  and store names in char array and grades in double array
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
}


/*
Purpose         : recieves the two grade arrays and calculates the average score
*/
void calculateAverageGrade(int *test1, int *test2, int *average){
    
    for(int i=0;i<6;i++){
        average[i] = (test1[i]+test2[i])/2;
    }
}

/*
Purpose         : recieves and sorts the grade array in descending order
*/
sortRecord(int *test1, int *test2, int *average){
    
    int swapavg=0, swaptest1=0, swaptest2=0;
    

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
            }
        }
    }

}

/*
Purpose         : re-reads the file to fetch the correct name
*/
sortNameRecord(int *test1, int *test2, char name_ordered[][10]){

    int i=0, t1=0, t2=0;
    char name[10];
    
    FILE *data;
    data = fopen("data.txt","r");
    if(data == NULL){
            printf("Error in file opening\n");
            return;
    }

    while(fscanf(data, "%s %d %d",name,&t1,&t2) != EOF){
        
        i++;
    }
}

// /*
// Purpose         : displays the student names, grade scores and average score in descending order
// */
// printRecord(){

// }

// /*
// Purpose         : displays the top average scorer of both exams
// */
// displayTopScorer(){

// }

int main(void){
    int test1[6];
    int test2[6];
    char name[6][10];
    char name_ordered[6][10];
    int average[6];

    getRecord(name,test1,test2);
    calculateAverageGrade(test1,test2,average);
    // for (int i=0;i<6;i++)
    //     printf("%s %d %d %d\n",name[i],test1[i],test2[i],average[i]);
    
    // printf("#########################\n");
    sortRecord(test1,test2,average);
    sortNameRecord(test1,test2,name_ordered)


    // for (int i=0;i<6;i++)
    //     printf("%s %d %d %d\n",name[i],test1[i],test2[i],average[i]);

            
    


    return 0;
}