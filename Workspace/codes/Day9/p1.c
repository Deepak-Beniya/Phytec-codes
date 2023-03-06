#include<stdio.h>
int main(){

    int a =10,b,c;
    sizeof(a++);
    a=(b=10,c=30);
     printf("%d\n",a);
    a++;
    printf("%d\n",c);
    ++a;
    printf("%d\n",a);

}