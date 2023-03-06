#include<stdio.h>
int main(){

    // int a,b;
    // a=15;
    // for(a>0,int i=0)
    // {
    //     a[i++]= a%2;
    //     a=a/2;
    // }
int i,a;
printf("Enter the value of a \n");
scanf("%d",&a);
printf("Binary form of a given number a: \n");

    for(int i= 7; i>=0; i-- ){

        int j =(a>>i) & 0x1;
        print("Position: %d",i);
        printf("Binary number:%d",j);
    }
    

    
}