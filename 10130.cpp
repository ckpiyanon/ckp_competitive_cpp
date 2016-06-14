#include <bits/stdc++.h>
using namespace std;
int dp[1010][3010],p[1000],w[1000];
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,g,ans,t;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++) scanf("%d %d",&p[i],&w[i]);
		scanf("%d",&g); ans = 0;
		for(int i = 0;i <= n;i++) for(int j = 0;j <= 30;j++)
		{
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(j < w[i-1]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j],p[i-1] + dp[i-1][j-w[i-1]]);
		}
		while(g--)
		{
			scanf("%d",&t);
			ans += dp[n][t];
		}
		printf("%d\n",ans);
	}
	return 0;
}
