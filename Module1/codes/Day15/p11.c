//5.WAP to store n elements in an array and print the element using pointers.

#include<stdio.h>

int main(){
    int i,n, *p;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    p=&arr[0];
    for(i=0;i<n;i++){
        printf("%d",*(p+i));
    }
    return 0;
}