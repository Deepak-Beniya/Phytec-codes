/*
Swaaping of two numbers without using third variable
*/
#include<stdio.h>
int main()
{
    int a,b;

    printf("Enter two numbers a & b:\n");
    scanf("%d%d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("after swapping the values of a:%d and b:%d\n",a ,b);
    

    return 0;
}