//Standard way to initialize the variable through structure members

#include<stdio.h>
struct s1 

{
    int empno;

}obj;



int main(){

    struct s1 obj={.empno=25};
    
    
    printf("%d\n",obj.empno);
    

}