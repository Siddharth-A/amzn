#include <stdio.h>
#include <iostream>

using namespace std;

void stopatPair(int num){
    if(num>=22 & num <=100){
        for(int i=num;i>=22;i--){
            if(num%11 == 0){
                printf("%d ",num);
                break;
            }
            else
                printf("%d ",num);
            num = num - 1;
        }
    }
    else{
        printf("Input not in range");
    }
}

int main(void){

int x = 7;
 x = x + 1;
if(x = 3) printf("UP\n");
else printf("Down\n");


    return 0;
}