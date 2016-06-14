#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int m,n,arr[101][101],area;
	memset(arr,0,sizeof(arr));
	while(~scanf("%d %d",&m,&n) && m && n)
	{
		area = 0;
		for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
			scanf("%d",&arr[i][j]),arr[i][j] += arr[i][j-1];
		for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
			arr[i][j] += arr[i-1][j];
		for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
		for(int k = i+1;k <= m;k++) for(int l = j+1;l <= n;l++)
			if(arr[k][l] - arr[k][j] - arr[i][l] + arr[i][j] == 0)
				area = max(area,(k-i)*(l-j));
		printf("%d\n",area);
	}
	return 0;
}
