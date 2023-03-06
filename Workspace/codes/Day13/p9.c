#include<stdio.h>

void main(){
    int a[5] = {4,5,6,3,2};
    int i,j,m;
    i=++a[1];
    j=a[1]++;
    m=a[i++];
    printf("%d,%d,%d",i,i,m);
    
}