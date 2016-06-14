#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC = 0,n,q,graph[100][100],u,v,w;
	while(~scanf("%d %d",&n,&q) && n && q)
	{
		memset(graph,-1,sizeof(graph));
		while(q--)
		{
			scanf("%d %d %d",&u,&v,&w);
			graph[u-1][v-1] = graph[v-1][u-1] = w;
		}
		for(int k = 0;k < n;k++)
			for(int i = 0;i < n;i++)
				if(graph[i][k] != -1)
					for(int j = 0;j < n;j++)
						if(graph[j][k] != -1)
							graph[i][j] = max(graph[i][j],min(graph[i][k],graph[k][j]));
		scanf("%d %d %d",&u,&v,&w);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",++TC,(int)ceil(w / (graph[u-1][v-1] - 1.0)));
	}

	return 0;
}
