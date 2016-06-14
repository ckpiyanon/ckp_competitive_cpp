#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m;

bool cmp(int a,int b)
{
    if(a%m == b%m)
    {
        if(a%2 == 0 && b%2 == 0)
            return a < b;
        else if(a%2 == 0 && b%2)
            return false;
        else if(a%2 && b%2 == 0)
            return true;
        return b < a;
    }
    return a%m < b%m;
}

int main()
{
    int arr[10000];
    int n;
    scanf("%d %d",&n,&m);
    while(n && m)
    {
        for(int i = 0;i < n;i++)
            scanf("%d",arr+i);
        sort(arr,arr+n,cmp);
        printf("%d %d\n",n,m);
        for(int i = 0;i < n;i++)
            printf("%d\n",arr[i]);
        scanf("%d %d",&n,&m);
    }
    printf("0 0\n");

    return 0;
}
