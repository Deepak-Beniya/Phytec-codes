#include<stdio.h>
#include<string.h>

struct dept
        {
           char branch[10];    
        }empdept;

struct employee {
        int empno;
        float salery;
        char name[10];
        struct dept empdept;
        
    };

int main(){
   struct employee emp1;

    
   
  emp1.empno=20;
  strcpy(emp1.name,"alex");
  emp1.salery=50000;
  strcpy(emp1.empdept.branch,"EEE");
  
 printf("%d %s %f %s",emp1.empno,emp1.name,emp1.salery,emp1.empdept.branch);
   
    return 0;
}