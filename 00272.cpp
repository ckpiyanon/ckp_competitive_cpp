#include <cstdio>
#include <cstring>

int main()
{
    char str[1000];
    int n;
    bool first = true;
    while(gets(str))
    {
        n = strlen(str);
        for(int i = 0;i < n;i++)
        {
            if(str[i] == '\"')
            {
                if(first)
                    printf("``");
                else
                    printf("\'\'");
                first = !first;
            }
            else
                printf("%c",str[i]);
        }
        printf("\n");
    }

    return 0;
}
