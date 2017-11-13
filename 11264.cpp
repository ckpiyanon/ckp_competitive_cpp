#include <cstdio>

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC,n,arr[1000],ans;
	long long sum;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)	scanf("%d",arr + i);
		sum = 0; ans = 1;
		for(int i = 0;i < n - 1;i++)
		{
			if(sum + arr[i] < arr[i + 1])
			{
				sum += arr[i];
				ans++;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
