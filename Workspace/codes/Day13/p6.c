//WAP  to use void pointers and use casting

#include<stdio.h>

int main(){

    void *p;
    int a=6;
    float f=14.67;
    char c='D';
    p=&a;
    printf("%d\n",*(int*)p);
    p=&f;
    printf("%f\n",*(float*)p);
    p=&c;
    printf("%c\n",*(char*)p);
   
    
    
    

}