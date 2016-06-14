#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int q,a,b;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        if(a < b || (a + b) % 2 || (b - a) % 2)
            printf("impossible\n");
        else if(a == b)
            printf("%d 0\n",2*a);
        else
            printf("%d %d\n",max((a + b)/2,(a - b)/2),min((a + b)/2,(a - b)/2));
    }

    return 0;
}
