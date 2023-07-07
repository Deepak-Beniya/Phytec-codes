#include<stdio.h>
int main(){
    int a[]={3,2,5,0,31,7,1,9};
    int *p=a;
    p++;
    printf("%d %d\n",*p++,*p++);
    printf("%d\n",*--p);
    printf("%d\n",*p--);
    printf("%u %u %u \n",*--p,*--p,*++p);
    
    return 0;
}