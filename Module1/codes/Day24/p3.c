#include<stdio.h>
#define POSITIVE
int main(){
 
#ifdef POSITIVE
	int a=10,b=20;
#endif
#ifdef NEGETAIVE 
	int a=-10,b=20;
#endif

	printf("value of addition is : %d ",a+b);
	printf("Value of subtraction is : %d ",a-b);
}
