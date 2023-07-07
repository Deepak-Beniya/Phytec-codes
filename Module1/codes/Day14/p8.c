#include<stdio.h>
int main(){
    int a=10,b=30;
    int *p,*q;
    p=&a;
    q=&b;
    *q=*p;
    printf("%d %d %d %d\n",a,*p,*q, *(&b));
    return 0;
}