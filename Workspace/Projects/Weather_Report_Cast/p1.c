#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int main()
{
    printf("This C program will exit in 10 seconds.\n");        

    delay(10);                        

    return 0;
}
