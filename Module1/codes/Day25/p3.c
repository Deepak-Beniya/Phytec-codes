#include<stdio.h>
struct cal 
{
    unsigned int d:5;
    unsigned int m:4;
    unsigned int y:12;

}__attribute__((packed))dt;

int main(){
    int d,m,y;
    

    printf("\nEnter the day: ");
    scanf("%d",&d);
    printf("\nEnter the Month: ");
    scanf("%d",&m);
    printf("\nEnter the year: ");
    scanf("%d",&y);

    struct cal dt={d,m,y};
    printf("\nDay :%d \n Month :%d \n Year :%d\n",dt.d,dt.m,dt.y); 
    printf("%ld\n",sizeof(dt));
    

}