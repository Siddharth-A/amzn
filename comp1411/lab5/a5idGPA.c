//*****************************************************************************
//* Program Name: a5idGPA.c
//* Your Name: Shalley Singh
//* Your ID: 1130765
//* Date: 08/11/2021
//*
//* Inputs: 
//* class_size       - number of students provided by the user
//* id               - in function getIDandGPA, the student ID of the student provided by user
//* gpa              - in function getIDandGPA, the GPA of the student provided by user
//*           
//* Outputs: 
//* none
//*
//* This program does the following:
//*     i. asks for the class size and creates array for the students ID and GPA
//*    ii. prints list of student ID and GPA sorted on the basis of GPA in ascending order
//*   iii. prints the student IDs with lowest GPA and GPA
//*    iv. prints the student IDs with highest GPA and GPA
//*     v. prints the average GPA of the students
//*****************************************************************************

#include <stdio.h>
/*
Purpose         : gets the ID and GPA of the student and stores it in array
Input           :    
                id array: array of all student IDs
                gpa array: array of all student GPA
                size: class size input by user

Output/Returns  :
                none
*/
void getIDandGPA(int id[], float gpa[], int size){
    for(int i=0; i<size; i++){
        printf("Enter Student #%d's ID: ",i+1);
        scanf("%d",&id[i]);
        printf("Enter Student #%d's GPA: ",i+1);
        scanf("%f",&gpa[i]);
        printf("\n");
    }
}

/*
Purpose         : arranges the GPA array in ascending order
Input           :    
                id array: array of all student IDs
                gpa array: array of all student GPA
                size: class size input by user

Output/Returns  :
                none
*/
void arrangeInAscendingOrder(int id[], float gpa[], int size){
    int swapid=0;
    float swapgpa=0;
    for(int i=0; i<size-1; i++){
        for(int j=0;j<size-i-1;j++){
            if(gpa[j] > gpa[j+1]){
                swapid = id[j];
                id[j] = id[j+1];
                id[j+1] = swapid;

                swapgpa = gpa[j];
                gpa[j] = gpa[j+1];
                gpa[j+1] = swapgpa;
            }
        }
    }
}

/*
Purpose         : prints out the minimum and maximum GPA and student # of students who achieved it
Input           :    
                id array: array of all student IDs
                gpa array: array of all student GPA
                size: class size input by user

Output/Returns  :
                none
*/
void displayMinMaxGPA(int id[], float gpa[], int size){
    float lowestgpa = gpa[0];
    float highestgpa = gpa[size-1];
    
    printf("Lowest GPA: %0.2f\n", lowestgpa);
    printf("List of students with lowest GPA: \n");
    for (int i=0;i<size;i++){
        if(gpa[i] == lowestgpa)
            printf("%d\n",id[i]);
    }

    printf("\n\n");

    printf("Highest GPA: %0.2f\n", highestgpa);
    printf("List of students with lowest GPA: \n");
    for (int i=0;i<size;i++){
        if(gpa[i] == highestgpa)
            printf("%d\n",id[i]);
    }

}

/*
Purpose         : prints out the minimum and maximum GPA and student # of students who achieved it
Input           :    
                gpa array: array of all student GPA
                size: class size input by user

Output/Returns  :
                none
*/
void displayAveGPA(float gpa[], int size){
    float average=0,sum=0;
    for (int i=0;i<size;i++){
        sum = sum + gpa[i];
    }
    average = sum/size;
    printf("The average GPA of the %d students is: %0.2f\n",size,average);

}

int main(void){
    int class_size=0;
    printf("Enter the Class Size: ");
    scanf("%d",&class_size);
    printf("\n\n");

    // create an empty id[] and gpa[] based on the size of class
    int id[class_size];
    float gpa[class_size];
    getIDandGPA(id, gpa, class_size);

    // arrange and print id and gpa arrays based on gpa in ascending order
    arrangeInAscendingOrder(id, gpa, class_size);
    printf("%s%15s\n","STUDENT ID","GPA");
    for(int i=0;i<class_size;i++){
        printf("%d                 %0.2f",id[i],gpa[i]);
        printf("\n");
    }
    printf("\n\n");

    // print the maximum and minimum gpa and student id of students who achieved it
    displayMinMaxGPA(id, gpa, class_size);
    printf("\n\n");

    // print and display the average gpa for the entire class
    displayAveGPA(gpa, class_size);

    return 0;
}
