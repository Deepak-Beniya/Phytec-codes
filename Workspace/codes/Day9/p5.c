//three number

#include<stdio.h>
int main(){

    int a,b ,c;
    printf("Enter the value of a: \n");
    scanf("%d",&a);
    
     
     c= a%5;
     if(c!=0)
     {
        printf("1st expression is evaluated\n");
     }
     else{
        printf("2nd expression is evaluated\n");
     }
    

    return 0;
}