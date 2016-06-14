#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int n1,n2,TC = 0,arr1[110],arr2[110];
	int tbl[110][110];
	while(~scanf("%d %d",&n1,&n2) && n1 && n2)
	{
		for(int i = 1;i <= n1;i++)
			scanf("%d",&arr1[i]);
		for(int i = 1;i <= n2;i++)
			scanf("%d",&arr2[i]);
		memset(tbl,0,sizeof(tbl));
		for(int i = 1;i <= n1;i++)	for(int j = 1;j <= n2;j++)
		{
			if(arr1[i] == arr2[j])	tbl[i][j] = tbl[i-1][j-1] + 1;
			else	tbl[i][j] = max(tbl[i-1][j-1],max(tbl[i-1][j],tbl[i][j-1]));
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++TC,tbl[n1][n2]);
	}

	return 0;
}
