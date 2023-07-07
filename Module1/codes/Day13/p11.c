#include<stdio.h>

int fun(int a[]){

return a[5]=10;
    
}

int main(void){
   
    int a[6]={1,2,3,4,5,6};
    printf("%d\n",a[5]);
    fun(a);
    printf("%d\n",a[5]);

}