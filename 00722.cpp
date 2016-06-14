#include <bits/stdc++.h>
using namespace std;
char arr[110][110];
int n,m,dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};
int cnt(int r,int c)
{
	if(r < 0 || c < 0 || r >= n || c >= m || arr[r][c] != '0')	return 0;
	arr[r][c] = '1';
	int ans = 1;
	for(int i = 0;i < 4;i++) ans += cnt(r + dr[i],c + dc[i]);
	return ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int r,c,TC;
	char s[31];
	TC = atoi(gets(s));
	gets(s);
	while(TC--)
	{
		gets(s);
		r = atoi(strtok(s," "));
		c = atoi(strtok(NULL," "));
		n = 0;
		while(gets(arr[n]) && strlen(arr[n])) n++;
		m = strlen(arr[0]);
		printf("%d\n",cnt(r-1,c-1));
		if(TC) printf("\n");
	}
	return 0;
}
