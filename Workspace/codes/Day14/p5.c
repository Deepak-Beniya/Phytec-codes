#include<stdio.h>
#include<stdarg.h>
int main(int argc, char const *argv[])
{
    /* code */
    int n,sum=0,i=1;
    for( i=1; i<argc; i++){

        sscanf(argv[i],"%d",&n);
        sum +=n;
    }

    printf("Sum is : %d ",sum);
    
    return 0;
}
