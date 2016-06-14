#include <bits/stdc++.h>
using namespace std;
char grid[50][100];
int dr[] = {0,0,1,-1},dc[] = {1,-1,0,0};
void floodfill(int r,int c)
{
	if(grid[r][c] != ' ' && grid[r][c] != '*') return;
	grid[r][c] = '#';
	for(int i = 0;i < 4;i++) floodfill(r + dr[i],c + dc[i]);
}
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n;
	scanf("%d ",&TC);
	while(TC--)
	{
		n = 0;
		while(true)
		{
			gets(grid[n]);
			if(grid[n++][0] == '_') break;
		}
		for(int i = 0;i < n;i++) for(int j = 0;grid[i][j] != '\0';j++)
			if(grid[i][j] == '*')
			{
				floodfill(i,j);
				i = n;
			}
		for(int i = 0;i < n;i++)
			puts(grid[i]);
	}

	return 0;
}
