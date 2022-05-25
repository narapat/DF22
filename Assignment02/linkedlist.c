/*

Task 2: Implementing a linked list of integer using pointer

Insertion: a function should be called void insert(int input);
Deletion: a function should be called int delete(int input); and it should delete the first occurrence of input in your linkedlist if exist. 
Print: : a function should be called void print();
Save the file as linkedlist.c
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
    /* data */
    int value;
    struct ListNode* next;
};

struct ListNode* CurPtr = NULL;
struct ListNode* HeadPtr = NULL;
struct ListNode* TailPtr = NULL;
int numberOfValue = 0;

void insert(int input){

    if (HeadPtr == NULL){
        // create new first node
        HeadPtr = (struct ListNode*)malloc(sizeof(struct ListNode));
        TailPtr = HeadPtr;
        HeadPtr->value = input;
        HeadPtr->next = NULL;
        printf("%d inserted as First Value",input);
        numberOfValue++;
    }else{

        // create new node
         CurPtr = (struct ListNode*)malloc(sizeof(struct ListNode));
         CurPtr->value = input;
         CurPtr->next = NULL;
         TailPtr->next = CurPtr;
         TailPtr = CurPtr;
         CurPtr = NULL;
         printf("%d inserted.",input);
         numberOfValue++;
    }
    
}

int delete(int input){
     int i=0;
     struct ListNode* TempPtr = NULL;
     if (numberOfValue==0){
         printf("No value in the list, skip deletion");
     }else if(HeadPtr->value==input){
            TempPtr = HeadPtr;
            HeadPtr = HeadPtr->next;
            TempPtr->next = NULL;
            free(TempPtr);
            i=1;
            numberOfValue--;
            printf("deleted first found of %d from position %d",input,i);
    }else if(HeadPtr->next != NULL){
            i=2;
            CurPtr = HeadPtr;
            TempPtr = CurPtr->next;
            while (TempPtr != NULL) {
                if(TempPtr->value == input){
                    CurPtr->next = TempPtr->next;
                    TempPtr->next = NULL;
                    free(TempPtr);
                    numberOfValue--;
                    printf("deleted first found of %d from position %d",input,i);
                }else{
                    CurPtr = TempPtr;
                    TempPtr = CurPtr->next;
                    i++;
                }
            }
        }else {printf("\nNo value found");}
     return i;   
}

void print(){
    CurPtr = HeadPtr;
    if(CurPtr != NULL) {
        printf("This is your current linked list : ");
        // print first node value
        printf("%d",CurPtr->value);   

        // print next node, if any
        while (CurPtr->next != NULL){
            CurPtr = CurPtr->next;
            printf(", %d",CurPtr->value);
        }
    } else {
        printf("\nNo value in list");
    }
}

int main(){
  char menu;
  int input;
  int exit = 0;

  printf("Welcome to dynamic linked list");
  do{
        printf("\nselect nemu\n put ""x"" to exit \n put ""p"" to print list \n put ""a"" to add value to list \n put ""d"" to delete latest value list\n: ");
        scanf("%s",&menu);
        switch (menu){
            case 'a':
                printf("Please provide integer value to add to linked list : ");
                scanf("%d",&input);
                insert(input);
                break;
            case 'd':
                printf("Please provide integer value to delete from linked list : ");
                scanf("%d",&input);
                delete(input);
                break;
            case 'p':
                //printf("This is your current linked list");
                print();
                break;
            case 'x':
                exit = 1;
            default:
                break;
        }
    } while(exit == 0);
    printf("\nThank you");
}
