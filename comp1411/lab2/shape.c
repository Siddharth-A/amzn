//*****************************************************************************
//* Program Name: shape.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 01/10/2021
//*
//* Inputs: 
//* radius  - stores radius of circle input by user
//* width   - stores width of rectangle input by user
//* height  - stores height of rectangle or triangle input by user
//* base    - stores base of triangle input by user
//* shape   - stores the shape the user wants to calculate area for
//*           
//* Outputs: 
//* area      - represents the area of the shape that the user chose
//*
//* This program calculates the area of shape that the user chose and provided 
//* dimensions for.
//*****************************************************************************

#include <stdio.h>

int main(void){
    // declare input variables
    float radius=0,width=0,height=0,base=0,pi=3.141592;
    int shape=0;
    // declare output variables
    float area=0;

    // printf statements to ask for input
    printf("Shape Menu\n 1. Circle\n 2. Rectangle\n 3. Triangle");
    printf("Shape (1,2 or 3)? ");
    // scanf statements to store input values in variables
    scanf("%d",&shape);

    // switch statement reads value of shape and goes to the same case #
    // if shape=1 then shape is circle
    // if shape=2 then shape is rectangle
    // if shape=3 then shape is traingle
    // if user provides bad input, default statement will exit program
    switch(shape){
        case 1:
            printf("radius? ");
            scanf("%f",&radius);
            area=pi*radius*radius;
            break;
        case 2:
            printf("width? ");
            scanf("%f",&width);
            printf("height? ");
            scanf("%f",&height);
            area=width*height;
            break;
        case 3:
            printf("base? ");
            scanf("%f",&base);
            printf("height? ");
            scanf("%f",&height);
            area=0.5*base*height;
            break;
        default:
            printf("%d is an invalid option.\n",shape);
            printf("program terminated.\n");
            // to exit program, default statement uses return statement instead of break
            return 0;
    }
    // print final area. to print float with only 3 decimal place, use %.3f instead of %f 
    printf("The area of the shape is %.3f square units. \n",area);

    return 0;
}