#include<stdio.h>

int main(void){

    int arr[]={10,11,12,15,23};
    printf("%u,%u\n",arr,&arr[3]);
    printf("%u,%u",arr,arr[3]);

    return 0;
}