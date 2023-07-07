#include<stdio.h>
#include<string.h>
struct department
{
  char dep[10];  
};


struct employee
{
    
    int salery;
    int age;
    
};



int main(){

    struct employee emp2;

    struct employee emp1={30000,48};

    
    emp2.salery=20000;
    emp2.age=37;

    struct employee emp3={10000,18};

    

    printf("Employee 1 :- %d   %d\n",emp1.salery,emp1.age);
    printf("Employee 2 :- %d   %d\n",emp2.salery,emp2.age);
   

}