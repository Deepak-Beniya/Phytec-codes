#include<stdio.h>

struct emp {
        int a;
        int *p;     
    }obj;

int main(){
   obj.a;
    obj.p=obj.a;
    
    
    printf("%d",sizeof(struct emp));

   // if(obj.a%sizeof()==0){
            printf("Alligned memory space\n");
    

    return 0;
}