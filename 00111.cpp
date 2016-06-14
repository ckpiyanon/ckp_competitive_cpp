#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int n,x,arr[30],dp[30],ma[30],ds;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&x);
		ma[x] = i;
	}
	while(scanf("%d",&x) != EOF)
	{
		arr[x] = 1;
		for(int i = 2;i <= n;i++)
		{
			scanf("%d",&x);
			arr[x] = i;
		}
		ds = 1;
		dp[0] = ma[arr[0]];
		for(int i = 1;i < n;i++)
		{
			x = arr[i];
			for(int j = ds-1;j >= 0;j--)
			{
				if(x > dp[j])
				{
					if(j == ds-1)
					{
						dp[j+1] = x;
						ds++;
					}
					else	dp[j+1] = min(x,dp[j+1]);
				}
			}
			dp[0] = min(dp[0],x);
		}
		printf("%d\n",ds);
	}

	return 0;
}
