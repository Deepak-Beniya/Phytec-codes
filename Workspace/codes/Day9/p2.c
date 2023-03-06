#include<stdio.h>
int main(){

    int a=0,b=0;
    printf("Enter the value of a: \n");
    scanf("%d",&a);
    printf("Enter the value of b: \n");
    scanf("%d",&b);

    if(a>b){
        printf("The greatest number is : %d",a);
    }

    if(b>a){
        printf("The greatest number is : %d",b);
    }

    return 0;
}