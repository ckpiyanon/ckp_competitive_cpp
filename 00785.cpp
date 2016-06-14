#include <bits/stdc++.h>
using namespace std;
char grid[30][81],border,from,to;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
void floodfill(int r,int c)
{
	if(grid[r][c] != from)	return;
	grid[r][c] = to;
	for(int i = 0;i < 4;i++)
		floodfill(r + dr[i],c + dc[i]);
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	bool found;
	char s[101];
	from = ' ';
	while(gets(s))
	{
		found = false;
		n = 0;
		while(true)
		{
			if(!found) for(int i = 0;s[i] != '\0';i++) if(s[i] != ' ') found = true,border = s[i];
			strcpy(grid[n++],s);
			if(s[0] == '_')	break;
			gets(s);
		}
		for(int i = 0;i < n;i++) for(int j = 0;grid[i][j] != '\0';j++)
		{
			if(grid[i][j] != ' ' && grid[i][j] != border && grid[i][j] != '_')
			{
				to = grid[i][j];
				for(int k = 0;k < 4;k++)
					floodfill(i + dr[k],j + dc[k]);
			}
		}
		for(int i = 0;i < n;i++)	puts(grid[i]);
	}

	return 0;
}
