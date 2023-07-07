#include<stdio.h>
void display();

int main(){

    display();
    display();
    display();
    display();
    display();
    display();

    


     return 0;
}

void display()
{
    static int x;
    x+=10;
    printf("\nx=%d",x);
}