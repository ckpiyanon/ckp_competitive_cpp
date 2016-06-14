#include <bits/stdc++.h>

long long arr[21][21][21];

long long foo(int upper,int left,int lower,int right,int level)
{
	return arr[level][lower][right] - arr[level][upper - 1][right] - arr[level][lower][left - 1] + arr[level][upper - 1][left - 1];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,a,b,c;
	long long ans,tmp;
	scanf("%d",&TC);
	while(TC--)
	{
		memset(arr,0,sizeof(arr));
		scanf("%d %d %d",&a,&b,&c);
		for(int i = 1;i <= a;i++) for(int j = 1;j <= b;j++) for(int k = 1;k <= c;k++)
			scanf("%lld",&arr[i][j][k]);
		/// Prefix sum for 3D
		for(int i = 1;i <= a;i++) for(int j = 1;j <= b;j++) for(int k = 1;k <= c;k++)
			arr[i][j][k] += arr[i][j][k-1];
		for(int i = 1;i <= a;i++) for(int j = 1;j <= b;j++) for(int k = 1;k <= c;k++)
			arr[i][j][k] += arr[i][j-1][k];
		for(int i = 1;i <= a;i++) for(int j = 1;j <= b;j++) for(int k = 1;k <= c;k++)
			arr[i][j][k] += arr[i-1][j][k];
		/// Finished prefix sum
		ans = LONG_LONG_MIN;
		for(int i = 0;i <= a;i++) for(int j = 0;j <= b;j++) for(int k = 0;k <= c;k++)
		for(int l = i;l <= a;l++) for(int m = j;m <= b;m++) for(int n = k;n <= c;n++)
		{
			if(i == l && j == m && k == n)	continue;
			tmp = foo(j,k,m,n,l) - foo(j,k,m,n,i);
//			printf("****** %d %d %d %d %d %d : %lld\n",i,j,k,l,m,n,tmp);
//			printf("%d\n",tmp);
			ans = std::max(ans,tmp);
		}
		printf("%lld\n",ans);
		if(TC)	printf("\n");
	}

	return 0;
}
