#include<stdio.h>

int main(void){

    int arr[]={12.4,2.3,4.5,6.7};
    printf("%u,%u\n",arr,&arr); // size of arr is 4 but int bit 4*4=16 and size of arr[0] is 4 so, 16/4 =4
    printf("%d\n",sizeof(arr)/sizeof(arr[0]));

    // int arr2[10] ={1,2,3,4,5};
    // printf("%d\n",arr[5]);
    // return 0;
    
}