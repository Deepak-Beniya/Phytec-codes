#include<stdio.h>
int main(){

  char ch;
   printf("enter the character : ");
   scanf("%c",ch);
   printf("%c",ch);

   if(ch=='a'|| ch=='e'|| ch=='i' || ch=='o'|| ch=='u')
   {

    printf("The entered charcter is vowel\n ");
   }

   if(ch=='A'|| ch=='E'|| ch=='I' || ch=='O'|| ch=='U')
   {

    printf("The entered charcter is vowel\n ");
   }
   
   else
   {
    printf("The entered charcter is consonant\n ");
   }
    

}