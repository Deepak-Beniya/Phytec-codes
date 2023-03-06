// Addition of two numbers using pointers

#include<stdio.h>
#include<string.h>

int main(){

   int a,b,c,*p,*q; 
   scanf("%d%d",&a,&b);
   p=&a;
   q=&b;
   c=*p+*q;
   printf("%d",c);
    return 0;
}