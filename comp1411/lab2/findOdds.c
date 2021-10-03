//*****************************************************************************
//* Program Name: findOdds.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 02/10/2021
//*
//* Inputs: 
//* first_num   - stores first number of range input by user
//* second_num  - stores second number of range input by user
//*           
//* Outputs: 
//*
//* This program prints the odd numbers between the range provided by user
//*****************************************************************************

#include <stdio.h>

int main(void){
    // declare input variables
    int first_num=0,second_num=0;
    // declare output variables
    float area=0;

    // printf & scanf statements to ask for input and store in variables
    printf("Enter the first number: ");
    scanf("%d",&first_num);
    printf("Enter the second number(> first number): ");
    scanf("%d",&second_num);

    // for loop starts at first number and ends at second num
    for(int i=first_num;i<=second_num;i++){
        // use modulus operator to check divisibility by 2
        if(i%2 != 0){
            printf("%d ",i);
        }   
    }

    return 0;
}