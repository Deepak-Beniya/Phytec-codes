// Using of unions and structure in real life aplication 

#include<stdio.h>
#include<string.h>
 
 typedef struct  
{
  int id;
  char name[30];
     union 
     { 
       struct inGame
        {
            int inID;
            char inName[20];
        }i; 

       struct outGame 
        {
          int ogID;
          char ogName[20];
        }o;

       
    };

}player;

int main(){


    for(int i=0;i<150;i++){
        printf("*");
    }
    printf("\n");
    
    printf("\t\t\t\t\t\tStudent Details in Sports\n");

    for(int i=0;i<150;i++){
        printf("*");
    }
    printf("\n");

    int n;
    char ch;

    printf("Enter the number of students:");
    scanf("%d",&n);

    player s[n];


    for(int i=0;i<n;i++)
    {
      printf("Enter the Student Name:");
      scanf(" %s",s[i].name);
      printf("\n");
      printf("Enter the student ID:");
      scanf("%d",&s[i].id);
      printf("\n");

      printf("Indoor(I) or Outdoor(O) Game:");
      scanf(" %c",&ch);
      printf("\n");

        if(ch=='I' || ch=='i'){
            
            printf("\nEnter the Indoor Game Name:");
            scanf("%s",s[i].i.inName);
            printf("\nEnter the Indoor Game ID:");
            scanf("%d",&s[i].i.inID);
            
        }
       if(ch=='O' || ch=='o') {
            printf("\nEnter the Outdoor Game Name:");
            scanf("%s",s[i].o.ogName);
            printf("\nEnter the Outdoor Game ID:");
            scanf("%d",&s[i].o.ogID);
            
       }
    }

   printf("The Entered student details are\n");

   for(int i=0;i<150;i++){
        printf("*");
    }
    printf("\n");

    for(int i=0;i<n;i++)
    {
      printf("\nStudent Name:%s",s[i].name);
      
      printf("\nThe student ID:%d\n",s[i].id);

      if(ch=='I' || ch=='i'){
            
            printf("\nThe Indoor Game is: %s",s[i].i.inName);
            printf("\nThe Indoor Game ID is: %d",s[i].i.inID);
            
            
        }
       if(ch=='O' || ch=='o') {
            printf("\nThe Outdoor Game is: %s",s[i].o.ogName);
            printf("\nThe Outdoor Game ID is: %d",s[i].o.ogID);
            
            
       }

    }
    


    return 0;
}


