#include<stdio.h>
#include"list.h"

int main(){

   int a;
   printf("1.Breakfast\n");
   printf("2.Lunch\n");
   printf("3.Dinner\n");
   printf("Enter the number between 1 to 3 : ");
   scanf("%d",&a);

   switch(a){
    
    case 1:
         breakfast(a);
           break;
    case 2:
         lunch(a);
         break;

    case 3:
         dinner(a);
         break;
    default : 
         printf("Enter the correct number :)");
         break;

   }
    return 0;
}