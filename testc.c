#include <stdio.h>

typedef struct node
{
    int n;
    int calculate()
    {
        return n * 6;
    };
}node;

int main()
{
    printf("Hello World.\n");

    return 0;
}
