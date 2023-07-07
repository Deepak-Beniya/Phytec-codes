#include<stdio.h>


int call(){    
  int c=5;
c++;
printf("Value of c :%d\n & Address of c :%u\n" ,c,&c);
 return 0;
}

 int main(){

    call();
    call();
    call();
    call();

   return 0;
 }