#include <cstdio>
#include <cstring>

int main()
{
    char str[1000],tmp[1000];
    char *tok;
    int len;
    while(gets(str))
    {
        tok = strtok(str," ");
        while(tok != NULL)
        {
            strcpy(tmp,tok);
            len = strlen(tmp);
            for(int i = len;i > 0;i--)
            {
                printf("%c",tmp[i-1]);
            }
            tok = strtok(NULL," ");
            if(tok)     printf(" ");
            else        printf("\n");
        }
    }

    return 0;
}
