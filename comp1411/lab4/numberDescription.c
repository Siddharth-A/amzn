//*****************************************************************************
//* Program Name: numberDescription.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 28/10/2021
//*
//* Inputs: 
//* input            - number provided by the user to analyze
//* user             - users input to the question "Do you wish to process another number"
//*           
//* Outputs: 
//* none
//*
//* This program analyzes the number provided by the user by calculating the following:
//*     i. is the number a palindrome?
//*    ii. lists the individual digits of the number
//*   iii. sum of the individual digits of the number
//*    iv. list of all primes numbers up until the sum of numbers
//*****************************************************************************

#include <stdio.h>

/*
Purpose         : reverses the digits of the input number

Input           :    
                number: number passed into the function

Output/Returns  :
                reverse: the number created by reversing digits of input number
*/ 
int reverse_number(int number){
    int temp=0,reverse=0;
    while(number != 0){
        temp = number%10;
        reverse = reverse*10 + temp;
        number = number/10;
    }
    return reverse;
}

/*
Purpose         : displays list of all prime numbers upto the input "sum"

Input           :    
                sum: sum of all digits calculated in digitSum
                (the upper limit up to which prime numbers are displayed)

Output/Returns  :
                none
*/ 
void listOfPrime(int sum){
    printf("List of prime digit of the sum of digits: ");
    while(sum != 0){
        for(int i=2;i<sum;i++){
            if(sum%i == 0){
                sum = sum - 1;
            }
        }
        printf("%d ",sum);
        sum = sum - 1;
    }
}

/*
Purpose         : displays individual digits of the number and calculates the sum of digits

Input           :    
                input: input provided by the user in main function

Output/Returns  :
                none
*/ 
void digitSum(int input){
    int sum=0, temp=0, reverse=0;
    printf("Individual digits of the input are: ");

    reverse = reverse_number(input);
    while(reverse != 0){
        temp = reverse%10;
        printf("%d ",temp);
        sum = sum + temp;
        reverse = reverse/10;
    }

    printf("\nSum of the individual digits: %d\n",sum);
    listOfPrime(sum);
}

/*
Purpose         : recieves the user input and determines if number is palindrome

Input           :    
                input: input provided by the user in main function

Output/Returns  :
                none
*/ 
void isPalindrome(int input){
    int reverse=0,temp=0;

    reverse = reverse_number(input);

    if(reverse == input)
        printf("The input provided is a palindrome\n");
    else
        printf("The input provided is not a palindrome\n");
}

int main(void){
    int input = 0;
    bool status = true;
    char user = ' ';

    while(status){
        // prompt user for input, if input is negative then terminate program
        printf("Enter a positive integer number: ");
        scanf("%d",&input);
        if(input < 0){
            printf("Invalid input error\n");
            printf("Program terminated\n");
            return 0;
        }
        
        // functions calls
        isPalindrome(input);
        digitSum(input);
        
        // code to prompt user repeatedly for input
        printf("\nDo you wish to process another number?[y/n]: ");
        scanf(" %c",&user);
        if(user == 'y')
            status = true;
        else if(user == 'n')
            status = false;
        else{
            printf("Invalid entry error\n");
            printf("Program terminated\n");
            return 0;
        }

    }
    return 0;
}