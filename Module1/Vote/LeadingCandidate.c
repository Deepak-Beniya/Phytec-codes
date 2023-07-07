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

void LeadingCandidate(){
    printf("\n\n  Leading Candidate \n\n");
    if(votes1>votes2 && votes1>votes3 && votes1 >votes4)
    printf("[%s]",candidate1);
    else if (votes2>votes3 && votes2>votes4 && votes2 >votes1)
    printf("[%s]",candidate2);
    else if(votes3>votes4 && votes3>votes2 && votes3 >votes1)
    printf("3[%s]",candidate3);
    else if(votes4>votes1 && votes4>votes2 && votes4 >votes3)
    printf("[%s]",candidate4);
    else
    printf("Warning !!! No-win situation");    
    
    
    
}