#include<stdio.h>
#include<string.h>

int result(int p,int c,int b,int i,int e,int m,int reg,char name[20]) {

    int sum= p + c + b + i + e +m;

 
    
    printf("Name :- %s\n",name);
    printf("Regestration No.:-%d\n",reg);
    printf("Physics:-%d\n",p);
    printf("Chemistry:-%d\n",c);
    printf("Biology:-%d\n",b);
    printf("Information Technology:-%d\n",i);
    printf("English :-%d\n",e);
    printf("Mathamatics :-%d\n",m);
    printf("Total Result :- %d\n",sum);


    if(sum>=500 && sum<600){

    printf("Grade :- A ");
 }

 if(sum>=400 && sum<500){

    printf("Grade :- B ");
 }

 if(sum>=300 && sum<400){

    printf("Grade :- C ");
 }

 if(sum>=198 && sum<300){

    printf("Grade :- D ");
 }

 if(sum<198){

    printf("Grade :- FAIL ");
 }
    




}