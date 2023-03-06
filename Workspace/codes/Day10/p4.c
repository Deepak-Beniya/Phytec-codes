#include<stdio.h>


 

int a=10;

 int main(){

   {
    static int a=1;
   // printf("%d\n",a);
   }

   static int a=2;
     {

      
     static int a=3;
      {
        printf("%d\n",a);
      }
    
  
      printf("%d\n",a);
    }

  printf("%d\n",a);
    
 }