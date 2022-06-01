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

    int i = 0;
    int matched = 0;
    struct ListNode* PreviousPtr = NULL;
    CurPtr = HeadPtr;
    PreviousPtr = CurPtr;
    if (CurPtr == NULL) {
        printf("No value in the list, skip deletion");
    } else {
        // Match
        while (CurPtr != NULL) {
            i=i+1;
            printf("compare polisiton %d \n",i);
            // Found and Only one Node
            if(CurPtr == HeadPtr && CurPtr == TailPtr && CurPtr->value == input){
                printf("only one node, match polisiton %d | ",i);
                printf("P:%d,C:%d,H:%d,T:%d \n",PreviousPtr->value,CurPtr->value,HeadPtr->value,TailPtr->value);
                HeadPtr = NULL;
                TailPtr = NULL;
                free(CurPtr);
                matched = 1;
                break;
            }
            // Found at First Node
            else if(CurPtr == HeadPtr && CurPtr->value == input){
                printf("first node, match polisiton %d | ",i);
                printf("P:%d,C:%d,H:%d,T:%d \n",PreviousPtr->value,CurPtr->value,HeadPtr->value,TailPtr->value);
                HeadPtr = HeadPtr->next;
                free(CurPtr);
                matched = 1;
                break;
            }
            // Found at Last Node
            else if(CurPtr == TailPtr && CurPtr->value == input){
                printf("last node, match polisiton %d | ",i);
                printf("P:%d,C:%d,H:%d,T:%d \n",PreviousPtr->value,CurPtr->value,HeadPtr->value,TailPtr->value);
                TailPtr = PreviousPtr;
                TailPtr->next = NULL;                
                free(CurPtr);
                matched = 1;
                break;
            }
            // Found at 2 .. (n-1) Node
            else if(CurPtr->value == input){
                printf("match polisiton %d | ",i);
                printf("P:%d,C:%d,H:%d,T:%d \n",PreviousPtr->value,CurPtr->value,HeadPtr->value,TailPtr->value);
                PreviousPtr->next = CurPtr->next;
                CurPtr->next = NULL;
                free(CurPtr);
                matched = 1;
                break;
            }
            // Not found fetch next node
            else{
                // Keep previous node in case of match at last node.
                PreviousPtr = CurPtr;
                CurPtr = CurPtr->next;
            }
        }
    }
    return matched;
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
                if(delete(input)==0){
                    printf("No matched value found in linked list : ");
                }
                break;
            case 'p':
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
