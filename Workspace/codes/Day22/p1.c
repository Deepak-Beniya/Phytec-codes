

#include<stdio.h>
#include<stdlib.h>

int main(){

   int *p,n;
   printf("\nEnter how many elements : ");
   scanf("%d",&n);
   p= (int *) malloc(n*sizeof(int));

   if(p==NULL)
   {
    fprintf(stderr,"\nFailed to allocate the memory");
    exit(1);
   }
   printf("\n Memory allocated at : %x ",p);
   printf("\n Intial values are :\n");

//    for(int i=0;i<n;i++)
//    {
//     printf("%d",p[i]);
//     printf("\n");
//    }
   for(int i=0;i<n;i++)
   {
    p[i]=i+1;
   }
   for(int i=0;i<n;i++)
   {
    printf("\n Memory allocated at : %d ",&p[i]);
    printf("\n%d",p[i]);
    printf("\n");
   }

   

    return 0;
}