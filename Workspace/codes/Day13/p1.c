#include<stdio.h>

int main(){

    int a,b,sum,*p;
    a=5;
    p=&a;
    printf("%x\n",p);
    printf("%x\n",p++);
     p++;
     printf("%x\n",p);
     p++;
    // *p++;
    printf("%x\n",p);
    printf("%x\n",p++);

     printf("\n");

     printf("%x\n",p);
    printf("%x\n",p--);
    p--;
    *p--;
    printf("%x\n",p);
    printf("%x\n",p--);
}