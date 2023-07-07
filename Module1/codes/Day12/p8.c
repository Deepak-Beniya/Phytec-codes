// WAP What is the maximum value of array
#include<stdio.h>
#include <stdint.h>
#define SIZE_MAX 429496729

int main(void){
    
    //int a=1;
    int num[SIZE_MAX];

    printf("PTRDIFF_MAX 0x%jx\n", (uintmax_t)PTRDIFF_MAX);
    printf("SIZE_MAX    0x%jx\n", (uintmax_t)SIZE_MAX);


   for(int i=0; i<SIZE_MAX-1;i++)
   {
    
    num[i]=i;

   }

   printf("%d",num[2]);

    return 0;
    

    

}