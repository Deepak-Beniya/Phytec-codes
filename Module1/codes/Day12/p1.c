// WAP get the data from the user at run time display on console

#include<stdio.h>

int main(){
int arr[5];

for(int i=0;i<5;i++){
    printf("Enter the value of array index %d: \n",i);
    scanf("%d",&arr[i]);

}

for(int i=0;i<5;i++){
    printf("The array of index %d : %d \n",i,arr[i]);
}

return 0;
}