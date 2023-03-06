//WAP implement arithmetic operation using call by referance and function call

#include<stdio.h>

int main(){
    int a=10, b=20;

    printf("Addition of a and b :%d\n", add(&a,&b));
    printf("subtraction of a and b :%d\n", sub(&a,&b));
    printf("Multiplication of a and b :%d\n", mup(&a,&b));
    printf("division of a and b :%d\n", div(&a,&b));
}

int add(int *x ,int *y){
 
    return *x+*y;
}

int sub(int *x ,int *y){
 
    return *x-*y;
}

int mup(int *x ,int *y){
 
    return *x * *y;
}

int div(int *x ,int *y){
 
    return *y / *x;
}