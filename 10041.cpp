#include <cstdio>
#include <cstdlib>

int abs(int n)
{
    return n < 0 ? -n:n;
}
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int TC,n,arr[500],t,ans;
    scanf("%d",&TC);
    while(TC--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&arr[i]);
        qsort(arr,n,sizeof(int),cmp);
        t = arr[n/2];
        ans = 0;
        for(int i = 0;i < n;i++)    ans += abs(t - arr[i]);
        printf("%d\n",ans);
    }

    return 0;
}
