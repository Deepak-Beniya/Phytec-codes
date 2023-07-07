#include<stdio.h>

int main(){
    int n;
    enum  {Maruti800=17,BMW,Swift=22, Alto=18,Tata=14};
  
  printf("\n Menu\n");
  printf("1. Maruti800\n");
  printf("2. BMW\n");
  printf("3. Swift\n");
  printf("4. Alto\n");
  printf("5. Tata\n");
  printf("Enter your Choice: \n");
  scanf("%d",&n);

  switch(n){

    case 1: printf("Milage is : %d ",Maruti800);break;
    case 2: printf("Milage is : %d ",BMW);break;
    case 3: printf("Milage is : %d ",Swift);break;
    case 4: printf("Milage is : %d ",Alto);break;
    case 5: printf("Milage is : %d ",Tata);break;
  }



}