#include <cstdio>
#include <cctype>
#include <cstring>

int val(char c)
{
    if(isalpha(c))
        return 1 + tolower(c) - 'a';
    return 0;
}
int cal(int a)
{
    int ans = 0;
    while(a >= 10)
    {
        ans = 0;
        while(a)
        {
            ans += a % 10;
            a /= 10;
        }
        a = ans;
    }
    return a;
}

int main()
{
    int a1,a2,len;
    char s[30];
    while(1)
    {
        a1 = a2 = 0;
        if(!gets(s))
            break;
        len = strlen(s);
        for(int i = 0;i < len;i++)
            a1 += val(s[i]);
        a1 = cal(a1);
        len = strlen(gets(s));
        for(int i = 0;i < len;i++)
            a2 += val(s[i]);
        a2 = cal(a2);
        printf("%.2lf %%\n",a1 > a2 ? ((a2*100.0)/(a1+0.0)):((a1*100.0)/(a2+0.0)));
    }

    return 0;
}
