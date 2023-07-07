#include<stdio.h>



int main(){

    struct leader
{
    char *lead;
    int born;
    
};

struct leader l1 ={"AbdulKalam",1931};
struct leader l2 = l1;
printf("%s %d",l2.lead,l1.born);
return 0;

}