#include <bits/stdc++.h>
#define INF 1000000
using namespace std;
int n,m,graph[30][30],u,v,w,TC = 0;
char name[30][30];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d %d",&n,&m) != EOF && n)
	{
		for(int i = 0;i < 30;i++) for(int j = 0;j < 30;j++) graph[i][j] = i == j ? 0:INF;
		for(int i = 0;i < n;i++) scanf("%s",name[i]);
		while(m--)
		{
			scanf("%d %d %d",&u,&v,&w); u--; v--;
			graph[u][v] = graph[v][u] = w;
		}
		for(int k = 0;k < n;k++) for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
			graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
		m = INF;
		for(int i = 0;i < n;i++)
		{
			w = 0;
			for(int j = 0;j < n;j++) if(i != j) w += graph[i][j];
			if(w < m) m = w,v = i;
		}
		printf("Case #%d : %s\n",++TC,name[v]);
	}

	return 0;
}
