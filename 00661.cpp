#include <cstdio>
#define mmax(a,b) (a > b ? a : b)

int main()
{
    bool state[20];
    int amp[20];
    int n,m,c,cnt = 0,cmax,cnow,t;
    while(scanf("%d %d %d",&n,&m,&c) != EOF)
    {
        if(n == 0 && m == 0 && c == 0)
            break;
        for(int i = 0;i < n;i++)
            scanf("%d",&amp[i]) , state[i] = false;
        cnow = 0;
        cmax = -1;
        printf("Sequence %d\n",++cnt);
        for(int i = 0;i < m;i++)
        {
            scanf("%d",&t);
            if(state[t-1])
            {
                cnow -= amp[t-1];
                state[t-1] = false;
            }
            else
            {
                cnow += amp[t-1];
                state[t-1] = true;
            }
            cmax = mmax(cmax,cnow);
        }
        if(cmax <= c)
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n",cmax);
        }
        else
        {
            printf("Fuse was blown.\n");
        }
        printf("\n");
    }

    return 0;
}
