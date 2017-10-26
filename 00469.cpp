#include <stdio.h>
#include <string.h>
#include <ctype.h>

char arr[110][110];
int w,h,ans,dr[8] = {-1,0,1,0,1,1,-1,-1},dc[8] = {0,-1,0,1,1,-1,1,-1};

void play(int r,int c)
{
    arr[r][c] = 'V';
    ans++;
    int i;
    for(i = 0;i < 8;i++)
    {
        if(arr[r+dr[i]][c+dc[i]] == 'W' && r+dr[i] < h && r+dr[i] >= 0 && c+dc[i] < w && c+dc[i] >= 0)
            play(r+dr[i],c+dc[i]);
    }
}

int main()
{
    char str[110],*p;
    int q,i,j,r,c;
    scanf("%d ",&q);
    while(q--)
    {
        i = 0;
        do
        {
            gets(str);
        }while(!strlen(str));
        w = strlen(str);
        while(isalpha(str[0]))
        {
            strcpy(arr[i++],str);
            gets(str);
        }
        h = i;
        do
        {
            sscanf(str,"%d %d",&r,&c);
            ans = 0;
            play(r-1,c-1);
            printf("%d\n",ans);
            for(i = 0;i < h;i++)
            {
                for(j = 0;j < w;j++)
                {
                    if(arr[i][j] == 'V')
                        arr[i][j] = 'W';
                }
            }
            p = gets(str);
        }while(strcmp(str,"") && p != NULL);
        if(q)
            printf("\n");
    }

    return 0;
}
