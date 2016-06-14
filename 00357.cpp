#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int coin[] = {1,5,10,25,50};
	long long dp[30001],n;
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 0;i < 5;i++)
		for(int j = coin[i];j <= 30000;j++)	dp[j] += dp[j - coin[i]];
	while(~scanf("%d",&n))
	{
		if(dp[n] == 1)	printf("There is only 1 way to produce %d cents change.\n",n);
		else			printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
	}

	return 0;
}
