//WAP a program to add numbers usng call by reference

#include<stdio.h>

int add(int *a,int *b){

    return *a+*b;
}

int main(){

   int a,b; 
   printf("Input the first number:");
   scanf("%d",&a);
   printf("Input the second number:");
   scanf("%d",&b);
   
   
   printf("%d",add(&a,&b));
    return 0;
}

