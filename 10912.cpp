#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	char s1[101],s2[101];
	int dp[101][101],l1,l2,TC = 0;
	memset(dp,0,sizeof(dp));
	while(gets(s1))
	{
		if(s1[0] == '#')	break;
		l1 = strlen(s1); l2 = strlen(gets(s2));
		for(int i = 1;i <= l1;i++) for(int j = 1;j <= l2;j++)
		{
			if(s1[i-1] == s2[j-1])	dp[i][j] = dp[i-1][j-1] + 1;
			else	dp[i][j] = max(dp[i-1][j-1],max(dp[i][j-1],dp[i-1][j]));
		}
		printf("Case #%d: you can visit at most %d cities.\n",++TC,dp[l1][l2]);
	}
	return 0;
}
