#include <bits/stdc++.h>

using namespace std;
char s[1001];
int dp[1001][1001];

int calc(int l,int r)
{
	if(l >= r)	return 0;
	if(dp[l][r] > -1)	return dp[l][r];
	return dp[l][r] = s[l] == s[r] ? calc(l+1,r-1):(min(min(calc(l+1,r),calc(l,r-1)),calc(l+1,r-1)) + 1);
}
int main()
{
	int TC;
	gets(s);
	TC = 0;
	while(gets(s))
	{
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",++TC,calc(0,strlen(s)-1));
	}

	return 0;
}
