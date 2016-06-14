#include <cstdio>

int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        n *= 63;
        n += 7492;
        n *= 5;
        n -= 498;
        if(n < 0)   n = -n;
        printf("%d\n",(n / 10) % 10);
    }

    return 0;
}
