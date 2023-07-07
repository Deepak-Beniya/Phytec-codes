#include<stdio.h>




int main(){

int a[10]={1,2,3,4,5,6,7,8,9,10},*p;
p=&a;

for(int i=0;i<=10;i++)
{
    printf("Value of array before change: %d  \n",a[i]);
}
printf("\n");
read(a);


    
}

int read(int a[]){
for(int i=0;i<=10;i++)
{
     a[i]=i+10;
    printf("Value of array after change: %d  \n",a[i]);
}
}

