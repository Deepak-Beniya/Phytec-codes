//WAP to swap two numbers using pointers
#include<stdio.h>

int main(){
    int a=6,b=8,*x,*y,temp;
    x=&a;
    y=&b;

    temp=*x;
    x=*y;
    y=temp;
    printf("%d\n",x);
    printf("%d\n",y);

}