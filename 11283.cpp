#include <cstdio>
#include <cstring>
#include <cstdlib>

char s[20];
char arr[4][4];
bool v[4][4];
int len;
int dr[] = { 0, 0, 1,-1, 1, 1,-1,-1};
int dc[] = {-1, 1, 0, 0,-1, 1,-1, 1};

int get_score(int n)
{
    if(n <= 4)
        return 1;
    if(n == 5)
        return 2;
    if(n == 6)
        return 3;
    if(n == 7)
        return 5;
    return 11;
}

bool play(int n,int r,int c)
{
    if(n == len-1)
        return true;
    bool tmp = false;
    int nr,nc;
    v[r][c] = true;
    for(int i = 0;i < 8;i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if(nr >= 4 || nc >= 4 || nr < 0 || nc < 0)
            continue;
        if(arr[nr][nc] == s[n+1] && !v[nr][nc])
            tmp = play(n+1,nr,nc);
        if(tmp)
            break;
    }
    v[r][c] = false;
    return tmp;
}

int main()
{
    int q,n,ans;
    scanf("%d",&q);
    for(int h = 1;h <= q;h++)
    {
        ans = 0;
        for(int i = 0;i < 4;i++)
            scanf("%s",arr[i]);
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",s);
            len = strlen(s);
            memset(v,0,sizeof(v));
            for(int r = 0;r < 4;r++)
            {
                for(int c = 0;c < 4;c++)
                {
                    if(arr[r][c] == s[0])
                    {
                        if(play(0,r,c))
                        {
                            ans += get_score(len);
                            c = 4,r = 4;
                        }
                    }
                }
            }
        }
        printf("Score for Boggle game #%d: %d\n",h,ans);
    }

    return 0;
}
