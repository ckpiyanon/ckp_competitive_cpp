#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int graph[100][100];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,ans = 0;
	char s[101];
	scanf("%d",&n);
	for(int i = 1;i < n;i++) for(int j = 0;j < i;j++)
	{
		scanf("%s",s);
		graph[i][j] = graph[j][i] = s[0] == 'x' ? INF:atoi(s);
	}
	for(int k = 0;k < n;k++) for(int i = 0;i < n;i++)
	if(graph[i][k] != INF) for(int j = 0;j < n;j++)
	{
		graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
	}
	for(int i = 0;i < n;i++) ans = max(ans,graph[0][i]);
	printf("%d\n",ans);

	return 0;
}
