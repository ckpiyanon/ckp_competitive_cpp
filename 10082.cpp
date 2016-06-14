#include <cstring>
#include <cstdio>

int main()
{
    char inp[101];
    char s1[] = "1234567890-=WERTYUIOP[]SDFGHJKL;'XCVBNM,./";
    char s2[] = "`1234567890-QWERTYUIOP[ASDFGHJKL;ZXCVBNM,.";
    char ma[256];
    memset(ma,0,256);
    int len = strlen(s1);
    for(int i = 0;i < len;i++)  ma[s1[i]] = s2[i];
    while(gets(inp))
    {
        len = strlen(inp);
        for(int i = 0;i < len;i++)
        {
            if(ma[inp[i]])  printf("%c",ma[inp[i]]);
            else            printf("%c",inp[i]);
        }
        printf("\n");
    }

    return 0;
}
