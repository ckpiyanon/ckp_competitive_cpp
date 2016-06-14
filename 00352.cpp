#include <bits/stdc++.h>
using namespace std;
char arr[30][30];
int n,dr[] = {1,-1,0,0,1,1,-1,-1},dc[] = {0,0,1,-1,1,-1,1,-1};
void floodfill(int r,int c)
{
	if(r < 0 || c < 0 || r >= n || c >= n || arr[r][c] != '1')	return;
	arr[r][c] = '0';
	for(int i = 0;i < 8;i++) floodfill(r + dr[i],c + dc[i]);
}
int main()
{
//	freopen("in.txt","r",stdin);
	int ans,TC = 0;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0;i < n;i++) scanf("%s",arr[i]);
		ans = 0;
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(arr[i][j] == '1')
			ans++,floodfill(i,j);
		printf("Image number %d contains %d war eagles.\n",++TC,ans);
	}
	return 0;
}
