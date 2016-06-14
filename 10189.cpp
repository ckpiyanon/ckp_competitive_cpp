#include <cstdio>

int main()
{
	int dr[] = {-1,-1,-1, 0, 0, 1, 1, 1};
	int dc[] = {-1, 0, 1,-1, 1,-1, 0, 1};
	int n,m,nr,nc,cnt = 0;
	char arr[100][101];
	scanf("%d %d ",&n,&m);
	while(n && m)
	{
		for(int i = 0;i < n;i++)	gets(arr[i]);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				if(arr[i][j] == '.')	arr[i][j] = '0';
		for(int r = 0;r < n;r++)
		{
			for(int c = 0;c < m;c++)
			{
				if(arr[r][c] == '*') for(int i = 0;i < 8;i++)
				{
					nr = r + dr[i];
					nc = c + dc[i];
					if(nr < 0 || nr >= n || nc < 0 || nc >= m || arr[nr][nc] == '*')	continue;
					arr[nr][nc]++;
				}
			}
		}
		printf("Field #%d:\n",++cnt);
		for(int i = 0;i < n;i++)
			puts(arr[i]);
		scanf("%d %d ",&n,&m);
		if(n && m)	printf("\n");
	}

	return 0;
}
