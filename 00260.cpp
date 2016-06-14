#include <bits/stdc++.h>
using namespace std;
bool side[2][2],dir; /** 1,true for white, 0,false for black **/
int n,dr[] = {-1,-1,0,0,1,1},dc[] = {-1,0,-1,1,0,1};
char from,arr[210][210];
const char to = 'f';
void floodfill(int r,int c)
{
	if(r < 0 || c < 0 || r >= n || c >= n || arr[r][c] != from) return;
	arr[r][c] = to;
	if(dir && c == 0)		side[1][0] = true;
	if(dir && c == n-1)		side[1][1] = true;
	if(!dir && r == 0)		side[0][0] = true;
	if(!dir && r == n-1)	side[0][1] = true;
	for(int i = 0;i < 6;i++) floodfill(r + dr[i],c + dc[i]);
}
int main()
{
//	freopen("in.txt","r",stdin);
	int TC = 0;
	while(~scanf("%d",&n) && n)
	{
		memset(side,false,sizeof(side));
		for(int i = 0;i < n;i++) scanf("%s",arr[i]);
		for(int i = 0;i < n;i++)
		{
			if(arr[i][0] == 'w')
			{
				from = 'w';
				dir = true;
				floodfill(i,0);
			}
			if(arr[0][i] == 'b')
			{
				from = 'b';
				dir = false;
				floodfill(0,i);
			}
		}
		printf("%d ",++TC);
		if(side[0][0] && side[0][1]) printf("B\n");
		else printf("W\n");
	}
	return 0;
}
