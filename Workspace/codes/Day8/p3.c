#include<stdio.h>
int main(){
  
  int a,b,c,d,e,f;
// printf("Enter the value of a \n");
// scanf("%d",&a);
// printf("Binary form of a given number a: \n");
    a= 4;
    b=5;
    printf("Binary of a:");
    for(int i= 7; i>=0; i-- ){

        int c =(a>>i) & 0x1;
        printf("%d",c);
        
    }
   printf("\n");
   printf("Binary of b:");
    for(int i= 7; i>=0; i-- ){

        int d =(b>>i) & 0x1;
        printf("%d",d);
        
    }
    e=a&b;
    printf("\n");
    printf("THE value of a&b: %d \n",e);
    for(int i=7;i>=0;i--){
      
     int j=(e>>i) & 0x1;
     printf("%d",j); 
    }

    f=a|b;
     printf("\n");
     printf("THE value of a|b: %d \n",f);
    for(int i=7;i>=0;i--){
      
     int j=(e>>i) & 0x1;
     printf("%d",j); 

    }


    


    return 0;
}