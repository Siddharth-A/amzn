// write program in c to recieve 3 int values 
// display the output

#include <stdio.h>

int main(void){
    // init variables
    int a=0,b=0,c=0;
    printf("Please enter three integers:");
    // scan user provided value and store to int
    scanf("%d %d %d",&a, &b, &c);
    printf("the three integers are: %d %d & %d\n", a,b,c);
    double avg = (a+b+c)/3.0;
    printf("the avg of three integers is: %f\n",avg);
}