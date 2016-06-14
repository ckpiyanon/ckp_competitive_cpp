#include <cstdio>
#include <cctype>
#include <cstring>

int dr[] = { 0, 0, 1,-1, 1, 1,-1,-1};
int dc[] = { 1,-1, 0, 0, 1,-1, 1,-1};
int len,r,c;
char s[51],arr[51][51];

bool play(int x,int y)
{
    int l,nr,nc;
    for(int i = 0;i < 8;i++)
    {
        l = 0,nr = x,nc = y;
        while(l < len && nr < r && nr >= 0 && nc < c && nc >= 0 && toupper(s[l]) == toupper(arr[nr][nc]))
        {
            l++;
            nr += dr[i];
            nc += dc[i];
        }
        if(l == len)    return true;
    }
    return false;
}

int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d ",&r,&c);
        for(int i = 0;i < r;i++)    gets(arr[i]);
        scanf("%d ",&n);
        while(n--)
        {
            gets(s);
            len = strlen(s);
            for(int i = 0;i < r;i++)
            {
                for(int j = 0;j < c;j++)
                {
                    if(play(i,j))
                    {
                        printf("%d %d\n",i + 1,j + 1);
                        i = r;
                        break;
                    }
                }
            }
        }
        if(q)   printf("\n");
    }

    return 0;
}
