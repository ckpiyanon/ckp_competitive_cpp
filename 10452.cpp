#include <cstdio>
#define LEN 8

char s[] = "@IEHOVA#";
char arr[10][10];
int dr[] = {-1,0,0};
int dc[] = {0,-1,1};
int m,n;

void play(int l,int r,int c)
{
    int nr,nc;
    if(l == LEN-1)
        return;
    for(int i = 0;i < 3;i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if(nr >= m || nc >= n || nr < 0 || nc < 0)
            continue;
        if(arr[nr][nc] == s[l+1])
        {
            switch(i)
            {
                case 0: printf("forth"); break;
                case 1: printf("left");  break;
                case 2: printf("right"); break;
                default:printf("Hi there");
            }
            if(s[l+1] != '#')
                printf(" ");
            play(l+1,nr,nc);
            break;
        }
    }
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&m,&n);
        for(int i = 0;i < m;i++)
            scanf("%s",arr[i]);
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(arr[i][j] == '@')
                    play(0,i,j);
            }
        }
        printf("\n");
    }

    return 0;
}
