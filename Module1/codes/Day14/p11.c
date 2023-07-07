#include<stdio.h>
int main(){
    int a[5]={1,3,5,-7,11};
    int *p=a;
    p=p+4;
    
    
    printf("%u %u %u\n",a,a[4],p);
    return 0;
}