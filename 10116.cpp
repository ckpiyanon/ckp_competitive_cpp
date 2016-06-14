#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	map<char,int> dir;
	dir['N'] = 0; dir['S'] = 1; dir['E'] = 2; dir['W'] = 3;
	int dr[] = {-1,1,0,0},dc[] = {0,0,1,-1};
	int r,c,n,m,p,ans,ans1;
	char grid[20][20];
	int arr[20][20];
	while(~scanf("%d %d %d",&n,&m,&c) && n && m && c--)
	{
		memset(arr,0,sizeof(arr));
		for(int i = 0;i < n;i++) scanf("%s",grid[i]);
		r = 0;
		ans = ans1 = 0;
		while(true)
		{
			if(r < 0 || r >= n || c < 0 || c >= m) break;
			if(arr[r][c]) {ans1 = ans - arr[r][c] + 1; ans -= ans1; break;}
			arr[r][c] = ++ans;
			p = dir[grid[r][c]];
			r += dr[p]; c += dc[p];
		}
		if(ans1 == 0) printf("%d step(s) to exit\n",ans);
		else printf("%d step(s) before a loop of %d step(s)\n",ans,ans1);
	}
	return 0;
}
