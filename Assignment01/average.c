
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Task 3: From Task 2 of assignment 1

Write another program to calculate the average
For example, input is [1, 2, 12, 20, 50, 8, 4]
Average is 13.85714
Save the file as average.c
*/

int toInt(char ListOfNumber[],int ArrayOfNumber[]){
    int iCountOfNumber=0;
    int i=0;
    printf("get string list : %s\n", ListOfNumber);
    char *token = strtok(ListOfNumber, ",");
    
    while (token != NULL) {
        ArrayOfNumber[i] = atoi(token);
        token = strtok(NULL,",");
        i++;
    }
    iCountOfNumber = i; 
return iCountOfNumber;
}

float arrayAVG(int ArrayOfNumber[], int SizeOfArray){
    float fAverage = 0.0;
    for(int i=0;i<SizeOfArray;i++){
        fAverage += ArrayOfNumber[i];
    }
    fAverage = fAverage/SizeOfArray;
    
return fAverage;
}

int main()
{ 
    char ListOfNumber[] = "1, 2, 12, 20, 50, 8, 4";
    int ArrayOfNumber[100];
    int Number = toInt(ListOfNumber, ArrayOfNumber);
    
    printf("Dispaly Array of Integer\n");
    for(int i=0;i<Number;i++){
        printf("position %d: %d\n", i, ArrayOfNumber[i]);
    }

    float Average = arrayAVG(ArrayOfNumber,Number);
    printf("Average of the list :%f",Average);

return 0;
}