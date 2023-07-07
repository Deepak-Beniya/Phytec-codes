#include<stdio.h>

void display();

int main(){

    int i;
    for(i=0;i<3;i++)
    {
        display();
        return 0;
    }
}

void display()
{
    static int x=5;
    int y=5;
    x++;
    y++;
    printf("x=%d\n",x);
    printf("y=%d\n",y);
}