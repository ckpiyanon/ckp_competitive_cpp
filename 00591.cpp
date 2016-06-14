#include <cstdio>

int main()
{
	int n,arr[50],total,ans,TC = 0;
	while(true)
	{
		scanf("%d",&n);
		if(n == 0)	break;
		total = 0;
		for(int i = 0;i < n;i++)	scanf("%d",arr + i),total += arr[i];
		total /= n;
		ans = 0;
		for(int i = 0;i < n;i++) if(arr[i] > total) ans += arr[i] - total;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",++TC,ans);
	}

	return 0;
}
