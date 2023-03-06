//WAP implement airthmetic operation using pointers to functions

#include<stdio.h>

int (*func)(int,int);
int add(int x,int y);
int sub(int x,int y);
int mup(int x,int y);
int div(int x,int y);
int main(){

    
    func=&add;
    printf("%d\n",add(15,5));
    func=&sub;
     printf("%d",sub(15,5));
     

}

int add(int x ,int y){
 
    return x+y;
}
int sub(int x ,int y){
 
    return x-y;
}

int mup(int x ,int y){
 
    return x * y;
}

int div(int x ,int y){
 
    return y / x;
}