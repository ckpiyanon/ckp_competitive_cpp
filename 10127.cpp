#include <cstdio>
#include <cstring>

int main()
{
    int n,rem,i;
    while(scanf("%d",&n) != EOF)
    {
        rem = 1,i = 0;
        while(1)
        {
            rem %= n;
            i++;
            if(!rem)    break;
            rem = rem*10 + 1;
        }
        printf("%d\n",i);
    }

    return 0;
}
