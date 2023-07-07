#include<stdio.h>
#define candidate1 "Narendra Modi"
#define candidate2 "Rahul Gandhi"
#define candidate3 "Arvind Kejriwal"
#define candidate4 "Donald Trumph"

int votes1=0;
int votes2=0;
int votes3=0;
int votes4=0;
int spoiledtvotes=0;

void votesC(){
printf("\n\n Voting Statics ");
printf("\n %s - %d ", candidate1, votes1);
printf("\n %s - %d ", candidate2, votes2);
printf("\n %s - %d ", candidate3, votes3);
printf("\n %s - %d ", candidate4, votes4);
printf("\n %s - %d ", "Spoiled Votes", spoiledtvotes); 
}