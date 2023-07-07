// WAP to find the size of modulo 5 of a given number is zero then print exoerssion 2 else expression 1 

#include<stdio.h>
int main(){

    int a,b ,c;
    printf("Enter the value of a: \n");
    scanf("%d",&a);
    
     
     c= a%5;
     if(c!=0)
     {
        printf("1st expression is evaluated");
     }
     else{
        printf("2nd expression is evaluated");
     }
      b = sizeof(c);
     printf("%d\n",b);

     


    return 0;
}