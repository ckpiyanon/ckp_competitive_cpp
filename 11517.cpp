#include <bits/stdc++.h>
#define INF 1000
using namespace std;
bool used[15001][100];
int coin[100],dp[15001];
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,num,n;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&num,&n);
		for(int i = 0;i < n;i++)	scanf("%d",&coin[i]);
		memset(used,false,sizeof(used));
		dp[0] = 0;
		for(int i = 1;i <= 15000;i++)	dp[i] = INF;
		for(int i = 0;;i++)
		{
			if(dp[i] == INF)	continue;
			bool unused = false;
			for(int j = 0;j < n;j++) unused |= !used[i][j];
			if(!unused)	break;
			for(int j = 0;j < n;j++)
			{
				if(!used[i][j])
				{
					if(dp[i + coin[j]] > dp[i] + 1)
					{
						for(int k = 0;k < n;k++)	used[i + coin[j]][k] = used[i][k];
						used[i + coin[j]][j] = true;
						dp[i + coin[j]] = dp[i] + 1;
					}
				}
			}
		}
		while(dp[num] == INF)	num++;
		printf("%d %d\n",num,dp[num]);
	}

	return 0;
}
