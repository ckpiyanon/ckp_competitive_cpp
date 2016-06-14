#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

int main()
{
	int l,n,arr[52],tbl[52][52],t;
	arr[0] = 0;
	memset(tbl,0,sizeof(tbl));
	scanf("%d",&l);
	while(l)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)	scanf("%d",arr + i);
		arr[n + 1] = l;
		for(int h = 2;h <= n+1;h++)
		{
			for(int i = 0;i + h <= n+1;i++)
			{
				t = INT_MAX;
				for(int j = i + 1;j < i + h;j++)	t = std::min(t,tbl[i][j] + tbl[j][i+h]);
				tbl[i][i + h] = arr[i + h] - arr[i] + t;
			}
		}
		printf("The minimum cutting is %d.\n",tbl[0][n+1]);
		scanf("%d",&l);
	}

	return 0;
}
