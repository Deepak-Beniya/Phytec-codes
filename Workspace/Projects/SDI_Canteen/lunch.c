#include<stdio.h>
#include"list.h"

int lunch(int a){


     int c, num;  
printf("Menu for Today's Lunch :)\n");
printf("1.VEG THALI          100 Rupees\n");
printf("2.NON-VEG THALI      100 Rupees\n");
printf("3.FISH THALI         100 Rupees\n");
printf("4.MUTTON THALI       100 Rupees\n");
printf("5.CHICKEN BIRIYANI   100 Rupees\n");
printf("Enter the number between 1 to 5: \n");
scanf("%d",&c);


printf("Quantity ?\n");
scanf("%d",&num);
 quant(a,num);

    return 0;
}