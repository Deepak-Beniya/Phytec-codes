#include<stdio.h>
    

int main(){

    struct employee
{
    int empid[5];
    int salary;
    int  *s;
    
}emp;

printf("%d %d",sizeof(emp),sizeof(emp.empid));
return 0;

}