//*****************************************************************************
//* Program Name: name_extract.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 20/11/2021
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
#include <ctype.h> //used for tolower and toupper
#include<string.h> //used for strtok

int main(void){
    bool status = true;
    char user = ' ';
    char email[200];
    char firstname[200];
    char lastname[200];

    // code to execute functions repeatedly
    while(status){
        printf("Enter an e-mail address -- ");
        scanf(" %s",email);

        // create first name
        int i=0;
        while(email[i]!='.'){
            firstname[i] = email[i];
            i++;
        }
        // add ending character and increment index for email
        firstname[i]='\0';
        i++;

        // create last name
        int j=0;
        while(email[i]!='@'){
            lastname[j] = email[i];
            i++;
            j++;
        }
        // add ending character
        lastname[j]='\0';

        // change lower to upper case
        firstname[0] = toupper(firstname[0]);
        lastname[0] = toupper(lastname[0]);

        printf("%s, ", lastname);
        printf("%s\n", firstname);

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