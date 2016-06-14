#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n,cnt = 0;
	long long arr[18],mmax,t;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0;i < n;i++)	scanf("%lld",&arr[i]);
		mmax = 0;
		for(int i = 0;i < n;i++)
			for(int j = i;j < n;j++)
			{
				t = 1;
				for(int k = i;k <= j;k++)	t *= arr[k];
				mmax = max(mmax,t);
			}
		printf("Case #%d: The maximum product is %lld.\n\n",++cnt,mmax);
	}

	return 0;
}
