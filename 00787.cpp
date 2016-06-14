#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	long long arr[100],ans,prod;
	while(scanf("%lld",&arr[0]) != EOF)
	{
		n = 1;
		while(true)
		{
			scanf("%lld",&arr[n]);
			if(arr[n] == -999999) break;
			n++;
		}
		ans = INT_MIN;
		for(int i = 0;i < n;i++)
		{
			prod = 1;
			for(int j = i;j < n;j++)
			{
				prod *= arr[j];
				ans = max(ans,prod);
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
