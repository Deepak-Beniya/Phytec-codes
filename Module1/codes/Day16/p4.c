#include<stdio.h>
    struct employee
{
    char *empname;
    int salary;
    
};

int main(){
struct employee e,e1;
e.empname ="Sridhar";
e1 = e;

printf("%s %s",e.empname,e1.empname);
return 0;

}