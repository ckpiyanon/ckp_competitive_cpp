#include <cstdio>
#include <cstring>
int main()
{
	int n;
	long long dp[10000];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 1;i <= 21;i++) for(int j = 0;j + i*i*i < 10000;j++)
		dp[j + i*i*i] += dp[j];
	while(scanf("%d",&n) != EOF)	printf("%lld\n",dp[n]);
	return 0;
}
