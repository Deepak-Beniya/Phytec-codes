/*
   WAP to filter the gps data depending upon the user
  GPS DATA :-  $GPGGA,181908.00,3404.7041778,N,07044.3966270,W,4,13,1.00,495.144,M,29.200,M,0.10,0000*40
*/ 

#include<stdio.h>

int main(){

char gps[] ={"$GPGGA,181908.00,3404.7041778,N,07044.3966270,W,4,13,1.00,495.144,M,29.200,M,0.10,0000*40"};
//char data[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
//int a;
// scanf("%d\n",&a);
// printf("%c\n",data[a]);


printf("Latitude is :");
for(int i=17;i<=28;i++){
printf("%c",gps[i]);
}

printf("\n");
printf("Longitude is :");
for(int i=32;i<=43;i++){
printf("%c",gps[i]);
}


}