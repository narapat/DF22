#include<stdio.h>
#include <string.h>


/*
Task 2: Write a program that read a string

The string contains list of numbers separated by a comma
Example: 1, 2, 12, 20, 50, 8, 4
Return an array of Integer
Example: [1, 2, 12, 20, 50, 8, 4]
Save the file as toInt.c
*/

void main()
{
    char ListOfNumber[] = "1,2,12,20,50,8,4";
    int ArrayOfInteger[30];
    int Asc;
    char tmp[3];
    //printf("Please enter list of number (with comma): ");
    //scanf("%s", ListOfNumber);
    int i = 0;
    int j = 0;
    printf("%c\n",ListOfNumber);

    do {
        //tmp="";
        int k = 0;
        if(ListOfNumber[i]!=44){
            printf("%c",ListOfNumber[i]);
            tmp[k]=ListOfNumber[i];
            i++;
            k++;
        }else{
            printf("%c\n",ListOfNumber[i]);
        }
        //Asc = (int)tmp;
        //ArrayOfInteger[j]=Asc;
        j++;
        i++;
    }
    while (i<sizeof(ListOfNumber));
/*
    for(int i=0;i<30;i++){
        printf("%d\n",ArrayOfInteger[i]);
    }
*/
}