#include <stdio.h>

struct name
{
    int a;
    char c;
    // unsigned int reserve[3];
    // unsigned char reserved[3];

    double d;

}__attribute__((packed));

int main()
{
    struct name temp = {10, 'D', 57.89};

    char *p = (double *)&temp;
    printf("\n value of d is: %lf", *(double *)(p + 5));
    printf("\n value of c is: %c", *(char *)(p + 4));

    printf("\n%ld\n", sizeof(temp));
    printf("\n %p", &temp.a);
    printf("\n%p", &temp.d);
    printf("\n%p\n", &temp.c);
}
