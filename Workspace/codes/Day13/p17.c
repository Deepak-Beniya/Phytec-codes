// WAP to check the sum of first 5 elements and sum of last 5 elements is equal or not

#include<stdio.h>

int main(void){

    int a[10];
    int sum1=0;
    int sum2=0;

    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
     for(int i=0;i<5;i++){
        
        sum1 = sum1 + a[i];
    }
     for(int i=5;i<10;i++){
        
        sum2 = sum2 + a[i];
    }

     if(sum1==sum2){
        printf("The sum of fist 5 element is equal to last 5 element\n");
     }
     else{
        printf("Sum is not equal\n");
     }

    printf("Sum1 is :%d\n",sum1);
    printf("Sum2 is :%d\n",sum2);
    return 0;
}