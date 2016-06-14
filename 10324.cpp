#include <cstdio>
#include <cstring>

#define swap(a,b) (a ^= b,b ^= a,a ^= b)

bool check(char *s,int begin,int end)
{
    bool ans = true;
    char tmp = s[end+1];
    s[end+1] = 0;
    if(strchr(s+begin,'0') && strchr(s+begin,'1'))
        ans = false;
    s[end+1] = tmp;
    return ans;
}

int main()
{
    char *s = new char[1000010];
    int i = 1,j = 1,n,c = 0;
    while(i || j)
    {
        scanf("%s %d",s,&n);
        printf("Case %d:\n",++c);
        while(n--)
        {
            scanf("%d %d",&i,&j);
            if(i > j)
                swap(i,j);
            printf("%s\n",check(s,i,j) ? "Yes":"No");
        }
    }

    return 0;
}
