// WAP TO SUM OF 10 INTEGER FROM USER IN AN ARRAY

#include<stdio.h>

int main(void){

    int a[10];
    int sum=0;

    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
     for(int i=0;i<10;i++){
        
        sum = sum + a[i];
    }
    printf("Sum is :%d",sum);
    return 0;
}