#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int tbl[110][110],n,ma,tmp;
    scanf("%d",&n);
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
            tbl[i][j] = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
            scanf("%d",&tbl[i][j]);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
            tbl[i][j] += tbl[i][j-1];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
            tbl[i][j] += tbl[i-1][j];
    }
    ma = -32768;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 0;k < i;k++)
            {
                for(int l = 0;l < j;l++)
                {
                    tmp = tbl[i][j] - tbl[i][l] - tbl[k][j] + tbl[k][l];
                    ma = max(ma,tmp);
                }
            }
        }
    }
    printf("%d\n",ma);

    return 0;
}
