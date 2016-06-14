#include <cstdio>

int main()
{
    int q,a,b;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        printf("%c\n",a == b ? '=':(a < b ? '<':'>'));
    }

    return 0;
}
