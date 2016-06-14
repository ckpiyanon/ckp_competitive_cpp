#include <cstdio>
#include <cstdlib>
#include <cstring>

int dr[] = {1,-1,0,0},dc[] = {0,0,1,-1},n;
int arr[100][100];
bool v[100][100];

int play(int val,int r,int c)
{
    if(r < 0 || r >= n || c < 0 || c >= n || arr[r][c] != val || v[r][c])   return 0;
    v[r][c] = true;
    int ans = 1;
    for(int i = 0;i < 4;i++)    ans += play(val,r + dr[i],c + dc[i]);
    return ans;
}

int main()
{
    int x,y;
    bool ans;
    char inp[10000],*p;
    while(true)
    {
        n = atoi(gets(inp));
        if(n == 0)  break;
        for(int i = 0;i < n;i++)    memset(arr[i],0,sizeof(arr[i])),memset(v[i],false,sizeof(v[i]));
        for(int i = 1;i < n;i++)
        {
            gets(inp);
            p = strtok(inp," ");
            while(p)
            {
                x = atoi(p);
                p = strtok(NULL," ");
                y = atoi(p);
                p = strtok(NULL," ");
                arr[x-1][y-1] = i;
            }
        }
        ans = true;
        for(int i = 0;i < n && ans;i++)
            for(int j = 0;j < n && ans;j++)
                if(!v[i][j])
                {
                    if(play(arr[i][j],i,j) != n)  ans = false;
                }
        if(ans) printf("good\n");
        else    printf("wrong\n");
    }

    return 0;
}
