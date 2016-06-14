#include <bits/stdc++.h>
using namespace std;
int dp[110][50100];
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,sum,arr[110],mm;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		sum = 0;
		for(int i = 0;i < n;i++)
			scanf("%d",&arr[i]),sum += arr[i];
		mm = sum / 2;
		for(int i = 0;i <= n;i++) for(int j = 0;j <= mm;j++)
		{
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(arr[i-1] <= j)
				dp[i][j] = max(arr[i-1] + dp[i-1][j - arr[i-1]],dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
		printf("%d\n",sum - dp[n][mm] - dp[n][mm]);
	}

	return 0;
}
