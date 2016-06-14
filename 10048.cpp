#include <bits/stdc++.h>
#define INF 538976288

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	bool first = true;
	int TC = 0,c,s,q,u,v,w,graph[100][100];
	while(~scanf("%d %d %d",&c,&s,&q) && c && s && q)
	{
		if(!first)	printf("\n");
		first = false;
		memset(graph,32,sizeof(graph));
		printf("Case #%d\n",++TC);
		while(s--)
		{
			scanf("%d %d %d",&u,&v,&w);
			graph[u-1][v-1] = graph[v-1][u-1] = w;
		}
		for(int k = 0;k < c;k++)
			for(int i = 0;i < c;i++)
				if(graph[i][k] != INF)
					for(int j = 0;j < c;j++)
						graph[i][j] = min(graph[i][j],max(graph[i][k],graph[k][j]));
		while(q--)
		{
			scanf("%d %d",&u,&v);
			if(graph[u-1][v-1] != INF)
				printf("%d\n",graph[u-1][v-1]);
			else
				printf("no path\n");
		}
	}

	return 0;
}
