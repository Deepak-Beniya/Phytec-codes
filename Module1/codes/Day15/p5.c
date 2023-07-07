#include<stdio.h>
#include<string.h>

struct employee {
        int empno;
        float salery;
        char name[10];
        
    };

int main(){
   struct employee a[2];
    
   for(int i=0;i<2;i++){
    scanf("%d%f%s\n",&a[i].empno,&a[i].salery,&a[i].name);
    
   }

   printf("\n \n");

   for(int i=0;i<2;i++){
    printf("%d\n",a[i].empno);
    printf("%s\n",a[i].name);
    printf("%f\n",a[i].salery);
   }
    return 0;
}