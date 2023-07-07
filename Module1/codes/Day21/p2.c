#include<stdio.h>
#include<string.h>
         
            struct outGame 
        {
          int ogID;
          char ogName[20];

        };

        struct inGame
        {
            int inID;
            char inName[20];
        }; 

    union games
     {
       struct outGame og;
       struct inGame ig;


     };

typedef struct  
{
  int id;
  char name[30];
  union games G;



}player;

int main(){

    player p1 ={19009, "Deepak",{12,"Cricket"},{15,"Chess"}};


printf("%d %s %d %s %d %s",p1.id, p1.name, p1.G.ig.inID,  p1.G.ig.inName, p1.G.og.ogID, p1.G.og.ogName );
 return 0;
}