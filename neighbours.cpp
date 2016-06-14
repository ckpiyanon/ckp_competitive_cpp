#include <cstdio>
#include <cstring>

int main()
{
	freopen("in.txt","r",stdin);
	int TC,x,y,pairs[9][9],ans[3][3],num[9];
	scanf("%d",&TC);
	for(int T = 0;T < TC;T++)
	{
		for(int i = 0;i < 9;i++)
		{
			num[i] = 0;
			for(int j = 0;j < 9;j++) pairs[i][j] = 0;
		}
		for(int i = 0;i < 12;i++)
		{
			scanf("%d %d",&x,&y);
			pairs[x][y] = pairs[y][x] = 1;
		}
		memset(ans,-1,sizeof(ans));
		for(int i = 0;i < 9;i++) for(int j = 0;j < 9;j++) if(pairs[i][j] == 1)	num[i]++;
		for(int i = 0;i < 9 && (ans[1][1] == -1 || ans[0][1] == -1);i++)
		{
			if(num[i] == 4)
			{
				ans[1][1] = i;
				num[i] = 0;
			}
			else if(num[i] == 3 && ans[0][1] == -1)
			{
				ans[0][1] = i;
				num[i] = 0;
			}
		}
		for(int i = 0;i < 9;i++)
		{
			if(num[i] == 2 && pairs[i][ans[0][1]] == 1)
			{
				if(ans[0][0] == -1)	ans[0][0] = i;
				else				ans[0][2] = i;
				num[i] = 0;
			}
		}
		for(int i = 0;i < 9;i++)
		{
			if(num[i] == 3)
			{
				if(pairs[i][ans[0][0]] == 1)
				{
					ans[1][0] = i;
					num[i] = 0;
				}
				else if(pairs[i][ans[0][2]] == 1)
				{
					ans[1][2] = i;
					num[i] = 0;
				}
			}
		}
		for(int i = 0;i < 9;i++)
		{
			if(num[i] == 3)
			{
				ans[2][1] = i;
				num[i] = 0;
			}
			else if(num[i] == 2)
			{
				if(pairs[i][ans[1][0]] == 1)
				{
					ans[2][0] = i;
					num[i] = 0;
				}
				else
				{
					ans[2][2] = i;
					num[i] = 0;
				}
			}
		}
		for(int i = 0;i < 3;i++)
		{
			for(int j = 0;j < 3;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
