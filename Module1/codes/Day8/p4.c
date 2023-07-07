#include<stdio.h>

int main(){
  
  int a,b,j,i,count=0;
 
printf("Enter the value of a \n");
scanf("%d",&a);
    
    
    for(i= 7; i>=0; i-- ){

        j =(a>>i) & 0x1;
        // printf("%d",j);
        if(j&1){
            count++;
        }
        
        //printf(count);
    }
    printf("%d",count);
}