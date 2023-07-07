#include<stdio.h>
#include<string.h>

typedef struct  
{
  int id;
  char name[30];

     union 
     {
        
       struct outGame 
        {
          int ogID;
          char ogName[20];

        }o;

       struct inGame
        {
            int inID;
            char inName[20];
        }i; 

        

     };

}player;

int main(){

    player p1 ={19009, "Deepak",10,"Cricket"};



printf("\n%d %s %d %s ",p1.id, p1.name, p1.i.inID , p1.i.inName);
 return 0;

}