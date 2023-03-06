#include<stdio.h>

int temp(float a)
{

    if(a>=35 || a<45)
    {
      printf("Today's weather is Sunny\n");
    }

    if(a>=30 || a<35)
    {
      printf("Today's weather is Mostly Sunny\n");
    }

     if(a>=25 || a<30)
    {
      printf("Today's weather is Haze\n");
    }

     if(a>=32 || a<35)
    {
      printf("Today's weather is Mostly Sunny\n");
    }

     if(a>=28 || a<30)
    {
      printf("Today's weather is Rainy\n");
    }

     if(a>=25 || a<28)
    {
      printf("Today's weather is Heavy Rainfall\n");
    }

     if(a>=23 || a<25)
    {
      printf("Today's weather is fog\n");
    }

}