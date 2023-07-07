#include<stdio.h>

int main(){

  int a,b,cho;
  enum {Add, Sub, Mul, Div, Square};

  printf("\n Menu\n");
  printf("0. Add\n");
  printf("1. Sub\n");
  printf("2. MUL\n");
  printf("3. Div\n");
  printf("4. Square\n");
  printf("Enter your Choice: \n");
  scanf("%d",&cho);
  printf("Enter the two numbers: ");
  scanf("%d%d",&a,&b);

  switch(cho){

    case 0: printf("Addition of a and b is : %d",a+b); break;
    case 1: printf("Subtraction of a and b is : %d",a-b); break;
    case 2: printf("Multiplication of a and b is : %d",a*b); break;
    case 3: printf("Division of a and b is : %d",a/b); break;
    case 4: printf("sum  of a and b then squaring : %d",(a+b)*2); break;

  }


    return 0;
}