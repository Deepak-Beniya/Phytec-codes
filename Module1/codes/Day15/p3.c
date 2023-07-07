#include<stdio.h>
#include<string.h>

struct employee {
        int empno;
        float salery;
        char name[10];
        
    }obj;

int main(){
   struct employee emp1,emp2,emp3;
    
    emp1.empno=10;
    
    strcpy(emp1.name,"alex");
    emp1.salery=50000;

    printf("%d %s %f",emp1.empno,emp1.name,emp1.salery);
    
    
    

    return 0;
}