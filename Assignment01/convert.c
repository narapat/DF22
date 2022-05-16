#include<stdio.h>

/*
Task 1: Write a program to convert all text to ALL CAPS

Use scanf to read a string input
Your program print out the same input to your screen but all letters are in CAPITAL LETTERS
Hint: ASCII Table is your friend
Save the file as convert.c
*/

int main()
{
    char SampleText[255];
    printf("Please enter Text: ");
    scanf("%s", SampleText);
    for(int i=0;i<255;i++){
        int Asc;
        Asc = (int)SampleText[i];
        //printf("Char %d :",i);
        //printf("%c\n",Asc);
        if(Asc>= 97){
            SampleText[i] = Asc-32;
        }
    }
    printf("Your Text : %s", SampleText);

return 0;
}