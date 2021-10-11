//*****************************************************************************
//* Program Name: calculateAverageGrade.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 09/10/2021
//*
//* Inputs: 
//* grade   - stores grade of each student input by user
//*           
//* Outputs: 
//* average - represents the calculated average
//*
//* This program calculates the total average of all grades entered by the user
//*****************************************************************************

#include <stdio.h>

/*
Purpose         : calculates the average for all grades entered by user

Input           :    
                sum: summation of all grades (float)
                counter: number of grades entered (float)

Output/Returns  :
                average: the average of all grades entered by user (float)
*/ 
float findAverage(float sum, float counter){
    float average = sum/counter;
    return average;
}

/*
Purpose         : calculaes the sum for all grades entered by user

Input           :    
                grade: grade of each student (float)

Output/Returns  :
                sum: the sum of all grades entered by user (float)
*/ 
float totalGrade(float grade){
    float sum = 0, counter = 0, avg;
    while(grade != -999){
        sum = sum + grade;
        counter++;
        printf("Enter grade (-999 to stop): ");
        scanf("%f",&grade);
    }
    avg = findAverage(sum,counter);
    printf("The average grade: %.2f\n",avg);
    return sum;
}

int main(void){
    float grade=0, sum=0;
    printf("Enter grade (-999 to stop): ");
    scanf("%f",&grade);
    if(grade != -999){
        sum = totalGrade(grade);
    }
    else{
        printf("no Valid Grade\n");
        printf("Program terminated!\n");
        return 0;
    }
    return 0;
}