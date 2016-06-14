#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int p,r,b,o,h,m,u,v,w;
	int graph[101][101],tg[101][101];
	bitset<101> notAble;
	char s[100];
	while(scanf("%d %d %d %d %d %d",&p,&r,&b,&o,&h,&m) != EOF)
	{
		notAble.reset();
		for(int i = 0;i <= 100;i++) for(int j = 0;j <= 100;j++)
			graph[i][j] = i == j ? 0:INF;
		while(r--)
		{
			scanf("%d %d %d",&u,&v,&w);
			graph[u][v] = graph[v][u] = w;
		}
		memcpy(tg,graph,sizeof(graph));
		for(int k = 1;k <= p;k++) for(int i = 1;i <= p;i++) for(int j = 1;j <= p;j++)
			graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
		for(int i = 1;i <= p;i++) if(graph[b][i] + graph[i][o] == graph[b][o]) notAble[i] = true;
		for(int k = 1;k <= p;k++)
		{
			if(notAble[k]) continue;
			for(int i = 1;i <= p;i++)
			{
				if(notAble[i]) continue;
				for(int j = 1;j <= p;j++)
				{
					if(notAble[j]) continue;
					tg[i][j] = min(tg[i][j],tg[i][k] + tg[k][j]);
				}
			}
		}
		if(tg[h][m] == INF || notAble[h] || notAble[m]) puts("MISSION IMPOSSIBLE.");
		else printf("%d\n",tg[h][m]);
	}

	return 0;
}
