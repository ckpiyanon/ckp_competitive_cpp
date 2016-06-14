#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int q,a,b,c;
    scanf("%d",&q);
    for(int i = 1;i <= q;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        printf("Case %d: %d\n",i,max(min(a,b),max(min(a,c),min(b,c))));
    }

    return 0;
}
