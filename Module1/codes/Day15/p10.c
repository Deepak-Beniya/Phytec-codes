//WAP to find the greatest number between two numbers using pointers

#include<stdio.h>

int greater(int *a,int *b){

    if(*a>*b)
    {
        return *a;
    }
    else {
        return *b;
    }
}

int main(){

   int a,b; 
   printf("Input the first number:");
   scanf("%d",&a);
   printf("Input the second number:");
   scanf("%d",&b);
   
   
   printf("Greater Number is:%d",greater(&a,&b));
    return 0;
}