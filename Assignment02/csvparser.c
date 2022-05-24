/*
Task 1: Implement a csv reader

Read a csv file called input.csv, where each entry contains an integer
Store the data in a 2D array
Calculate the average of each row of data, save this in the 1D output array
Print the result
Save your program as csvparser.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int avgInt(int input[5][10],float output[10], int row, int col){
    int iSUM = 0;
    for(int i=0;i<row;i++){
        iSUM = 0;
        for(int j=0;j<col;j++){
            iSUM += input[i][j];       
        }
        output[i] = iSUM/col;
    }

    return 0;
}

int toInt(char ListOfNumber[],int ArrayOfNumber[5][10],int row){
    int iCountOfNumber=0;
    int i=0;
    printf("get string list : %s\n", ListOfNumber);

    //
    char *token = strtok(ListOfNumber, ",");
    
    while (token != NULL) {

        //convert string to integer
        ArrayOfNumber[row][i] = atoi(token);

        // fetch next token
        token = strtok(NULL,",");
        i++;
    }
    iCountOfNumber = i; 
return iCountOfNumber;
}

int main()
{
    int row = 0;
    int col = 0;
    int input[5][10];
    float output[10];

    FILE* file = fopen("input.csv", "r"); /* should check the result */
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        col = toInt(line,input,row);
        //printf("found %d cols\n", col); 
        row++;
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
    if (feof(file)){
        printf("\nfound %d rows, average number for each row :\n",row);
        avgInt(input,output,row,col);
        for(int i=0;i<row;i++){
            printf("%f,",output[i]);
        }
        fclose(file);
    }else 
        printf("\n Something went wrong.");
    
    return 0;
}