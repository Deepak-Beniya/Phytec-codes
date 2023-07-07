//WAP implement addition example by using call by referance and functions

#include<stdio.h>

//  float count(float *c){

//     ++*c;
// }
//int add(int *,int *);
int add(int *a,int *b){

    return *a+*b;
}
int main(){

    // float f=10.4;
    // f=5.2;
    // printf("%f",f);
    // count(&f);

int c=5,d=8;
int e= add(&c,&d);
printf("%d",e);

}