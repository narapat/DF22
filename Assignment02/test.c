#include<stdio.h>

int main(){

    int a;
    int *b;

    a = 1;
    b = &a;
    

    printf("%d,%x",a, *b);
    scanf("%d",&a);
    printf("%d,%x",a, *b);



    return 0;

}