#include<stdio.h>
int main(){

int a[10],*p;
p=&a;
printf("%x\n",*(p+8));    
}