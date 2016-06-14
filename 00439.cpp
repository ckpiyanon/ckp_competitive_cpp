#include <utility>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;

int dr[] = { 2, 2,-2,-2, 1, 1,-1,-1};
int dc[] = {-1, 1,-1, 1,-2, 2,-2, 2};
int tbl[8][8];
char inp1[3],inp2[3];

void bfs(int r,int c)
{
	int nr,nc;
	queue<ii> q;
	tbl[r][c] = 0;
	q.push(make_pair(r,c));
	while(!q.empty())
	{
		r = q.front().X;
		c = q.front().Y;
		q.pop();
		for(int i = 0;i < 8;i++)
		{
			nr = r + dr[i],nc = c + dc[i];
			if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8)	continue;
			if(tbl[nr][nc] > tbl[r][c] + 1)
			{
				tbl[nr][nc] = tbl[r][c] + 1;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

int main()
{
	while(scanf("%s %s",inp1,inp2) != EOF)
	{
		for(int i = 0;i < 8;i++)	for(int j = 0;j < 8;j++)	tbl[i][j] = 2000000000;
        bfs(inp1[0] - 'a',inp1[1] - '1');
        printf("To get from %s to %s takes %d knight moves.\n",inp1,inp2,tbl[inp2[0] - 'a'][inp2[1] - '1']);
	}

	return 0;
}
