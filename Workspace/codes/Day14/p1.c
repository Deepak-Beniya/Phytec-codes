#include<stdio.h>
int main(){



     void *p;
    int a=6;
    float f=14.67;
    char c='D';
    double d=123.76;
    p=&a;
    printf("%d\n",sizeof(p));
    p=&f;
    printf("%d\n",sizeof(p));
    p=&c;
    printf("%d\n",sizeof(p));
    p=&d;
    printf("%d\n",sizeof(p));
}