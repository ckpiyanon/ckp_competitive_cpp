#include <bits/stdc++.h>
#define INF 10000

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int graph[20][20];
	int u,v,n,X = 0;
	while(scanf("%d",&n) != -1)
	{
		printf("Test Set #%d\n",++X);
		memset(graph,1,sizeof(graph));
		for(int i = 0;i < 20;i++)	graph[i][i] = 0;
		for(int i = 0;i < 19;i++)
		{
			while(n--)
			{
				scanf("%d",&v),v--;
				graph[i][v] = graph[v][i] = 1;
			}
			if(i < 18)	scanf("%d",&n);
		}
		for(int k = 0;k < 20;k++) for(int i = 0;i < 20;i++) for(int j = 0;j < 20;j++)
			graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d %d",&u,&v);
			printf("%2d to %2d: %d\n",u,v,graph[u-1][v-1]);
		}
		printf("\n");
	}

	return 0;
}
