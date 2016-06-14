#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>

int getScore(char *s)
{
    int len = strlen(s),p = 0,ans = 0;
    for(int i = 0;i < len;i++)
    {
        if(toupper(s[i]) == 'X')        p = 0;
        else if(toupper(s[i]) == 'O')   ans += ++p;
    }
    return ans;
}

int main()
{
    char s[100];
    int TC = atoi(gets(s));
    while(TC--)     printf("%d\n",getScore(gets(s)));

    return 0;
}
