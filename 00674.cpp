#include <bits/stdc++.h>
#define NUMCOINS 5

using namespace std;

int dp[8000];
int coin[] = {1,5,10,25,50};

int main()
{
//	freopen("in.txt","r",stdin);
	int inp;
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 0;i < NUMCOINS;i++) for(int j = coin[i];j < 8000;j++)
		dp[j] += dp[j - coin[i]];
	while(scanf("%d",&inp) != EOF)
		printf("%d\n",dp[inp]);

	return 0;
}
