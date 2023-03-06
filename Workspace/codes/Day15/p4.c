#include<stdio.h>
#include<string.h>

struct employee {
        int empno;
        float salery;
        char name[10];
        
    }obj;

int main(){
   struct employee emp[2]={{12,3456,"dog"},{74,8999,"cat"}};
    
   for(int i=0;i<2;i++){
    printf("%d\n",emp[i].empno);
    printf("%s\n",emp[i].name);
    printf("%f\n",emp[i].salery);
   }

    //printf("%d %s %f\n",emp1.empno,emp1.name,emp1.salery);
    
    
    

    return 0;
}