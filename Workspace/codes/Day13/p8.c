//WAP implement airthmetic operation using pointers to functions

#include<stdio.h>

int (*func)(int,int);
int add(int x,int y);
int sub(int x,int y);
int mup(int x,int y);
int div(int x,int y);
int main(){

    
    func=&add;
    //printf("%d\n",add(15,5));
    func=&sub;
     //printf("%d",sub(15,5));
     
     char a;
     scanf("%c",&a);
     switch(a){
        case '+':
              printf("Addition of a and b :%d\n", add(20,10));
              break;
        case '-':
             printf("subtraction of a and b :%d\n", sub(20,10));
             break;
        case '*':
            printf("Multiplication of a and b :%d\n", mup(20,10));
            break;
        case '/':
            printf("division of a and b :%d\n", div(20,10));
            break;               
              
     }
     

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