#include<stdio.h>
#define ODD

int main(){
  
   #ifdef EVEN 
	int a =10, b=20;
   #elif defined ODD
	int a=7,b=9;
   #else 
	int a=0,b=0;
   #endif
	printf("Value is :%d ",a+b);


}
