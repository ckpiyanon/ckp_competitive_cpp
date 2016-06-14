#include <bits/stdc++.h>
#define INF 1000000
using namespace std;
int graph[100][100];
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,m,u,v;
	scanf("%d",&TC);
	for(int x = 1;x <= TC;x++)
	{
		scanf("%d %d",&n,&m);
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
			graph[i][j] = i == j ? 0:INF;
		while(m--)
		{
			scanf("%d %d",&u,&v);
			graph[u][v] = graph[v][u] = 1;
		}
		for(int k = 0;k < n;k++) for(int i = 0;i < n;i++)
		if(graph[i][k] != INF) for(int j = 0;j < n;j++)
			graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
		scanf("%d %d",&u,&v);
		m = 0;
		for(int i = 0;i < n;i++) m = max(m,graph[u][i] + graph[i][v]);
		printf("Case %d: %d\n",x,m);
	}
	return 0;
}
