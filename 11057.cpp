#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n,arr[10000],m,ans;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0;i < n;i++)	scanf("%d",arr + i);
		sort(arr,arr + n);
		scanf("%d",&m);
		for(int i = 0;i < n;i++)
		{
			if(binary_search(arr + i + 1,arr + n,m - arr[i]))
				ans = arr[i];
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans,m - ans);
	}

	return 0;
}
