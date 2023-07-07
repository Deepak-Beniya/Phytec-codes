#include<stdio.h>
#include"list.h"

int breakfast(int a){


  int c, num;  
printf("Menu for Today's Breakfast :)\n");
printf("1.PURI       10 Rupees\n");
printf("2.EDLY       10 Rupees\n");
printf("3.VADA       10 Rupees\n");
printf("4.DOSA       10 Rupees\n");
printf("5.UTTHAPUM   10 Rupees\n");
printf("Enter the number between 1 to 5: \n");
scanf("%d",&c);


printf("Quantity ?\n");
scanf("%d",&num);
quant(a,num);



return 0 ;

}

