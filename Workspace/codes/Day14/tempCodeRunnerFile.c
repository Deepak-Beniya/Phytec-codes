#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int sum = 0, n;
    if (strcmp(argv[1], "-s") == 0)
        

    for (int i = 1; i < argc; i++)
    {
        sscanf(argv[i], "%d", &n);

        
            sum += n;
        
    }
    printf("%d", sum);
}