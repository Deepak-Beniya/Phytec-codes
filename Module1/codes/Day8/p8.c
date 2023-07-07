#include<stdio.h>
int main(){
int REG_LED ;
   REG_LED =15;
   REG_LED=REG_LED^(1<<1);

   int a,j;
printf("Enter the value of a \n");
scanf("%d",&a);
printf("Binary form of a given number a: \n");
for(int i=7; i>=0; i--){
    int j =(a>>i) & 0x1;
    printf("%d",j);
    // j=j^(1>>1);
    // printf("%d\n",j);
   //printf("%d",REG_LED);
}
printf("\n");
j=j^(1>>1);
    printf("%d\n",j);


return 0;
}