#include <bits/stdc++.h>
using namespace std;
int dp[40][1010],d[40],p[40];
bitset<40> yes;
void ans(int n,int t)
{
	if(n == 0 || t == 0) return;
	if(dp[n-1][t] == dp[n][t]) ans(n-1,t);
	else if(dp[n][t] == p[n-1] + dp[n-1][t - d[n-1]])
		yes[n-1] = true,ans(n-1,t - d[n-1]);
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,w,n,num;
	bool first = true;
	while(scanf("%d %d",&t,&w) != EOF)
	{
		if(!first) printf("\n");
		first = false;
		scanf("%d",&n);
		for(int i = 0;i < n;i++) scanf("%d %d",&d[i],&p[i]),d[i] *= w*3;
		yes.reset();
		for(int i = 0;i <= n;i++) for(int j = 0;j <= t;j++)
		{
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(j < d[i-1]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j],p[i-1] + dp[i-1][j-d[i-1]]);
		}
		printf("%d\n",dp[n][t]);
		num = 0; yes.reset(); ans(n,t);
		for(int i = 0;i < n;i++) num += yes[i];
		printf("%d\n",num);
		for(int i = 0;i < n;i++) if(yes[i])
			printf("%d %d\n",d[i] / 3 / w,p[i]);
	}

	return 0;
}
