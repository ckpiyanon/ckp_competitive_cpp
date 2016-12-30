#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC,n;
	long long dp[52];
	dp[0] = dp[1] = 1;
	for(int i = 2;i <= 51;i++)	dp[i] = dp[i-1] + dp[i-2];
	scanf("%d",&TC);
	for(int tc = 1;tc <= TC;tc++)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n%lld\n\n",tc,dp[n+1]);
	}

	return 0;
}
