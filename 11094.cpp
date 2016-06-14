#include <bits/stdc++.h>
using namespace std;
char grid[21][21];
char land,water;
int m,n;
int dr[] = {1,-1,0,0,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1,1,-1};
int floodfill(int r,int c)
{
	if(c < 0) c += n;
	if(c >= n) c -= n;
	if(r < 0 || r >= m || grid[r][c] != land)	return 0;
	int ret = 1;
	grid[r][c] = water;
	for(int i = 0;i < 4;i++)
		ret += floodfill(r + dr[i],c + dc[i]);
	return ret;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int x,y,mm,X = 0;
	while(scanf("%d %d",&m,&n) != EOF)
	{
		for(int i = 0;i < m;i++)
		{
			scanf("%s",grid[i]);
//			for(int j = 0;j < n;j++) grid[i][j] = tolower(grid[i][j]);
		}
		mm = 0;
		scanf("%d %d",&x,&y); land = grid[x][y];
		for(char c = 'a';c <= 'z';c++) if(c != land) {water = c; break;}
		for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(grid[i][j] != land)
			water = grid[i][j],i = m,j = n;
		floodfill(x,y);
//		printf("\n%d FILLED\n",++X);
		for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(grid[i][j] == land)
			mm = max(mm,floodfill(i,j));
		printf("%d\n",mm);
	}

	return 0;
}
