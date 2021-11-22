//*****************************************************************************
//* Program Name: main.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 11/11/2021
//*
//* Inputs: 
//* input[2]       - input array used to store the numerator and denominator values provided by user
//* user           - users input to the question "Try again[Y/N]"
//*           
//* Outputs: 
//* none
//*
//* This program does the following:
//*     i. executes getFraction function which asks user for numerator and denominator values
//*    ii. executes gcd function which then finds the greatest common divisor between numerator and denominator and returns it
//*   iii. executes reduce function which divides numerator and denominator with gcd and prints that value
//*****************************************************************************

#include <stdio.h>
/*
Purpose         : prompts the user to enter numerator and denominator of a fraction
Input           :    
                *input: pointer to a 2 integer array, used to store user input values

Output/Returns  :
                input:  returns the input array after populating it with values
*/
int *getFraction(int *input){
    printf("\nEnter the numertor and denominator -- ");
    scanf("%d %d",&input[0],&input[1]);
    return input;
}

/*
------> FUNCTION IS NOT USED IN ASSIGNMENT <-------
Purpose         : takes two input integers and returns the smaller integer
*/
int smallest(int num1, int num2){
    if(num1 < num2)
        return num1;
    else
        return num2;
}

/*
Purpose         : returns the greatest common divisor of two integers
Input           :    
                numerator: derived from numdenom array, it is the numerator value
                denominator: derived from numdenom array, it is the denominator value

Output/Returns  :
                gcd:  returns the greatest common divisor of two input values
*/
int gcd(int numerator, int denominator){
    int gcd = 0;
    // printf("gcd\n");
    for(int i=1; i<=numerator && i<=denominator;i++){
        if(numerator%i==0 && denominator%i==0){
            gcd=i;
        }
    }
    // printf("gcd done\n");
    return gcd;
}

/*
Purpose         : prints the reduced form of numerator and denominator
Input           :    
                numerator: derived from numdenom array, it is the numerator value
                denominator: derived from numdenom array, it is the denominator value
                gcd:  greatest common divisor of numerator and denominator

Output/Returns  :
                none
*/
void reduce(int numerator, int denominator, int gcd){
    int reduced_num = numerator/gcd;
    int reduced_denom = denominator/gcd;

    printf("the reduced fraction is -- %d/%d",reduced_num,reduced_denom);
}

int main(void){
    int *numdenom;
    // input array is needed so user values entered in getFraction can be brought to main
    int input[2];
    int gcdval = 0;
    bool status = true;
    char user = ' ';

    // code to execute functions repeatedly
    while(status){
        numdenom = getFraction(input);
        gcdval = gcd(numdenom[0],numdenom[1]);
        reduce(numdenom[0],numdenom[1],gcdval);

        // code to prompt user repeatedly for input
        printf("\nTry again[Y/N] -- ");
        scanf(" %c",&user);
        if(user == 'y' || user == 'Y')
            status = true;
        else if(user == 'n' || user == 'N')
            status = false;
        else{
            printf("Invalid entry error\n");
            printf("Program terminated\n");
            return 0;
        }
    }

    return 0;
}