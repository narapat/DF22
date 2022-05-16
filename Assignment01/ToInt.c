#include<stdio.h>
#include <stdlib.h>
#include<string.h>


/*
Task 2: Write a program that read a string

The string contains list of numbers separated by a comma
Example: 1, 2, 12, 20, 50, 8, 4
Return an array of Integer
Example: [1, 2, 12, 20, 50, 8, 4]
Save the file as toInt.c
*/
int toInt(char ListOfNumber[],int ArrayOfNumber[]){
    int CountOfNumber=0;

    printf("get string list : %s\n", ListOfNumber);
    char* token = strtok(ListOfNumber, ",");
    int i=0;
    while (token != NULL) {
        ArrayOfNumber[i] = atoi(token);
        printf("%d\n", ArrayOfNumber[i]);
        token = strtok(NULL,",");
        i++;
    }
    CountOfNumber = i; 
return CountOfNumber;
}

int main()
{
    char ListOfNumber[] = "1,2,12,20,50,8,4";
    int ArrayOfNumber[100];
    int number = toInt(ListOfNumber, ArrayOfNumber);
    printf("Dispaly Array of Integer\n");
    for(int i=0;i<number;i++){
        printf("%d:%d\n", i,ArrayOfNumber[i]);
    }
return 0;
}