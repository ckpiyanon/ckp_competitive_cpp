#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

char arr[101][101];
int n,m;
int dr[] = {-1,-1,-1,0,0,1,1,1},dc[] = {-1,0,1,-1,1,-1,0,1};

int floodfill(int r,int c,char from,char to)
{
	int ans = 1;
	arr[r][c] = to;
	for(int i = 0;i < 8;i++)
	{
		int nr = r + dr[i],nc = c + dc[i];
		if(nr >= 0 && nc >= 0 && nr < n && nc < m && arr[nr][nc] == from)
			ans += floodfill(nr,nc,from,to);
	}
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int q,r,c;
	char s[101];
	scanf("%d",&q);
	while(q--)
	{
		int i = 0;
		while(~scanf("%s",s) && isalpha(s[0]))
			memcpy(arr[i++],s,101);
		n = i; m = strlen(arr[0]);
		while(isdigit(s[0]))
		{
			r = atoi(s); scanf("%d",&c);
			printf("%d\n",floodfill(r-1,c-1,'W','X'));
			floodfill(r-1,c-1,'X','W');
			scanf("%s",s);
		}
		if(q)	puts("");
	}

	return 0;
}
