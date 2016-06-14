#include <cstdio>
#include <cstdlib>

int main()
{
	int TC,n,arr[20],ans;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)	scanf("%d",arr + i);
		qsort(arr,n,sizeof(int),[](const void *a,const void *b){return *(int*)a - *(int*)b;});
		ans = arr[n-1] - arr[0];
		for(int i = 1;i < n;i++)	ans += arr[i] - arr[i-1];
		printf("%d\n",ans);
	}

	return 0;
}

