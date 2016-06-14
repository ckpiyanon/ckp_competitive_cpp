#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,arr[50],cnt;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++) scanf("%d",arr + i);
		cnt = 0;
		for(int i = n-1;i > 0;i--) for(int j = 0;j < i;j++) if(arr[j] > arr[j+1])
		{
			arr[j] ^= arr[j+1],arr[j+1] ^= arr[j],arr[j] ^= arr[j+1];
			cnt++;
		}
		printf("Optimal train swapping takes %d swaps.\n",cnt);
	}

	return 0;
}
