#include<stdio.h>
#include<stdlib.h>
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
    int iCountOfNumber=0;
    int i=0;
    printf("get string list : %s\n", ListOfNumber);

    //
    char *token = strtok(ListOfNumber, ",");
    
    while (token != NULL) {

        //convert string to integer
        ArrayOfNumber[i] = atoi(token);

        // fetch next token
        token = strtok(NULL,",");
        i++;
    }
    iCountOfNumber = i; 
return iCountOfNumber;
}

int main()
{ 
    
    char ListOfNumber[255];
    int ArrayOfNumber[100];
    int number = 0;
    printf("Provide list of number sparate by comma : ");
    scanf("%s",ListOfNumber);
    number = toInt(ListOfNumber, ArrayOfNumber);
    printf("Dispaly Array of Integer\n");
    for(int i=0;i<number;i++){
        printf("position %d: %d\n", i, ArrayOfNumber[i]);
    }
return 0;
}