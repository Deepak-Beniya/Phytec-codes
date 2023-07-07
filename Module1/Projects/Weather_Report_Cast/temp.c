#include<stdio.h>
#include"myheader.h"

int temp(float *b)
{
    // float b = *a;
    printf("\ntemp:-%f\n",*b);

    if(*b>=35 && *b<45)
    {
      printf("Today's weather is Sunny\n");
    }

    if(*b>=30 && *b<35)
    {
      printf("Today's weather is Mostly Sunny\n");
    }

     if(*b>=25 && *b<30)
    {
      printf("Today's weather is Haze\n");
    }

     if(*b>=32 && *b<35)
    {
      printf("Today's weather is Mostly Sunny\n");
    }

     if(*b>=28 && *b<30)
    {
      printf("Today's weather is Rainy\n");
    }

     if(*b>=25 && *b<28)
    {
      printf("Today's weather is Heavy Rainfall\n");
    }

     if(*b>=23 && *b<25)
    {
      printf("Today's weather is fog\n");
    }

    return 0;
}
