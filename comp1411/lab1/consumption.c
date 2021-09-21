//*****************************************************************************
//* Program Name: consumption.c
//* Your Name: Shalley Singh
//* Your ID: ssingh87
//* Date: 21/09/2021
//*
//* Inputs: 
//* distance        - stores distance between two cities input by user
//* avg_consumption - stores average consumption of fuel per 100km input by user
//* fuel_cost       - stores cost of fuel per liter input by user
//*           
//* Outputs: 
//* final cost      - represents the final cost of the trip between the two cities
//*
//* This program calculates the cost to drive between two cities
//*****************************************************************************

#include <stdio.h>

int main(void){
    // declare input variables
    float distance,avg_consumption,fuel_cost;
    // declare output variables
    float final_cost;

    // printf statements to ask for input
    // scanf statements to store input values in variables
    printf("Enter the distance between the 2 cities in km: ");
    scanf("%f",&distance);
    printf("Enter the average consumption per 100 km: ");
    scanf("%f",&avg_consumption);
    printf("Enter the fuel cost per liter in $: ");
    scanf("%f",&fuel_cost);

    // formula to calculate cost:
    // distance needs to be divided by 100.0 to give float value not 100
    final_cost=(distance/100.0)*(avg_consumption)*(fuel_cost);

    // print final cost. to print float with only 4 decimal place, use %.4f instead of %f 
    printf("The cost to drive between the 2 cities is $%.4f\n",final_cost);
    return 0;
}