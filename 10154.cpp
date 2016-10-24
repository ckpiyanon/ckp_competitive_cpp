#include <bits/stdc++.h>
#define strength first
#define weight second

using namespace std;
typedef pair<int,int> ii;

int main()
{
//	freopen("in.txt","r",stdin);
	int x,y,mmax;
	vector<ii> arr;
	vector<int> dp;
	while(~scanf("%d %d",&x,&y))	arr.push_back(ii(y,x));
	sort(arr.begin(),arr.end());
	dp = vector<int>(arr.size() + 1);
	dp.assign(dp.size(),INT_MAX);
	dp[0] = 0;
	mmax = 0;
	for(vector<ii>::iterator it = arr.begin();it != arr.end();it++)
	{
		for(int j = mmax;j >= 0;j--)
		{
			x = it->weight + dp[j];
			if(x <= it->strength && x < dp[j+1])
				dp[j+1] = x,mmax = max(mmax,j+1);
		}
	}
	printf("%d\n",mmax);

	return 0;
}
