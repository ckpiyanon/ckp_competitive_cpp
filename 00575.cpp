#include <cstdio>
#include <cstring>

int main()
{
    char s[40];
    long long ans;
    int len;
    while(gets(s))
    {
        len = strlen(s);
        if(len == 1 && s[0] == '0')
            break;
        ans = 0;
        for(int i = len;i > 0;i--)
        {
            ans += (s[i-1] - '0') * ((1 << (len - i + 1)) - 1);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
