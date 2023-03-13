#include<stdio.h>
#include<string.h>
struct department
{
  char dep[10];  
};


struct employee
{
    char name[20];
    int salery;
    struct department d;
};



int main(){

    struct employee emp2,emp3;

    struct employee emp1={"Deepak",30000};

    strcpy(emp2.name,"Satyam");
    emp2.salery=20000;

    

    printf("Employee 1 :- %s   %d\n",emp1.name,emp1.salery);
    printf("Employee 2 :- %s   %d\n",emp2.name,emp2.salery);
   

}
