#include<stdio.h>

struct emp {
        int empno;
        float salery;
        char name;
        
    }asa;

int main(){

    
    asa.empno=565;
    printf("%d\n",asa.empno);
    printf("%d",sizeof( struct emp));
    

    return 0;
}