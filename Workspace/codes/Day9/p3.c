#include<stdio.h>
int main(){

    int a,b ,c;
    printf("Enter the value of a: \n");
    scanf("%d",&a);
    
     
     c= a%2;
     if(c==0)
     {
        printf("The given number is even");
     }
     else{
        printf("the given number odd");
     }


    return 0;
}