#include <cstdio>
#include <cstring>
int arr[110],dp[110][110];
int play(int a,int b)
{
	if(dp[a][b] >= 0)	return dp[a][b];
	if(a == b)	return 0;
	int tmp;
	for(int i = a;i < b;i++)
	{
		tmp = play(a,i) + play(i+1,b) + ((arr[i] - arr[a-1]) % 100)*((arr[b] - arr[i]) % 100);
		if(dp[a][b] < 0 || dp[a][b] > tmp)	dp[a][b] = tmp;
	}
	return dp[a][b];
}
int main()
{
	int n;
	for(int i = 0;i < 110;i++)	dp[i][i] = 0;
	while(scanf("%d",&n) != EOF)
	{
		memset(dp,-1,sizeof(dp));
		for(int i = 1;i <= n;i++)	scanf("%d",arr + i),arr[i] += arr[i-1];
		printf("%d\n",play(1,n));
	}

	return 0;
}
