#include<stdio.h>
#include"list.h"

int dinner(int a){


     int c, num;  
printf("Menu for Today's Dinner :)\n");
printf("1.NAAN + CHICKEN KASA          100 Rupees\n");
printf("2.NAAN + MUTTON KASA           100 Rupees\n");
printf("3.ROTI + CHICKEN TANDORI       100 Rupees\n");
printf("4.NON-VEG BIRIYANI             100 Rupees\n");
printf("5.CHICKEN BIRIYANI             100 Rupees\n");
printf("Enter the number between 1 to 5: \n");
scanf("%d",&c);


printf("Quantity ?\n");
scanf("%d",&num);
quant(a,num);

    return 0;
}