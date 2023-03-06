//6.WAP to swap elements using call by referance

#include<stdio.h>

int swap(int*, int*, int*);
int arr[7]={1,2,3,4,5,7};
int arr2[5];
int main(){
    int a,b,c;
    int arr3[5];
    printf("%d\n",arr[5]);
    printf("%d\n",arr2[3]);
    printf("%d\n",arr3[3]);
    // scanf("%d%d%d",&a,&b,&c);
    // swap(&a,&b,&c);
    // printf("%d\n%d\n%d\n",a,b,c);
}

int swap(int *x, int *y, int *z){
    int temp = *y;
    *y=*x;
    *x=*z;
    *z = temp;

}