//*****************************************************************************
//* Program Name: calculatePhoneBill.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 11/10/2021
//*
//* Inputs: 
//* mins            - minutes of phone call used input by user
//* account number# - maccount number of the plan input by user
//* phone plan      - premium or regular plan input by user
//*           
//* Outputs: 
//* balance         - represents the calculated outstanding balance for the user
//*
//* This program calculates and displays the balance/bill, account number, 
//* and minutes usage when the user inputs the minutes of phone call. 
//*****************************************************************************

#include <stdio.h>

/*
Purpose         : calculates the balance for regular phone plan

Input           :    
                mins: minutes used by called (float)

Output/Returns  :
                balance: the cost of phone plan (float)
*/ 
float regular(float mins){
    float balance;
    float basic_rate = 15;
    float free_mins = 100;
    float rate = 0.25;
    if(mins<=free_mins){
        balance = basic_rate;
    }
    else{
        balance = basic_rate + ((mins-free_mins)*rate);
    }
    return balance;
}

/*
Purpose         : calculates the balance for premium phone plan

Input           :    
                mins: minutes used by called (float)

Output/Returns  :
                balance: the cost of phone plan (float)
*/ 
float premium(float mins){
    float balance;
    float basic_rate = 25;
    float free_mins = 200;
    float rate = 0.15;
    if(mins<=free_mins){
        balance = basic_rate;
    }
    else{
        balance = basic_rate + ((mins-free_mins)*rate);
    }
    return balance;
}

int main(void){
    int account=0;
    char service = ' ';
    float balance = 0, mins = 0;

    printf("Enter user account number: ");
    scanf("%d",&account);
    printf("Enter type of service (r for regular, p for premium): ");
    scanf(" %c",&service);

    if(service == 'r' | service == 'R'){
        printf("Enter minutes usage: ");
        scanf("%f",&mins);
        balance = regular(mins);
    }
    else if(service == 'p' | service == 'P'){
        printf("Enter minutes usage: ");
        scanf("%f",&mins);
        balance = premium(mins);
    }
    else{
        printf("Wrong service type\n");
        printf("Program terminated!\n");
        return 0;
    }
    printf("Account Number      Minutes Usages      Balance\n");
    printf("%d                %.0f                 $%.2f\n",account,mins,balance);
    return 0;
}