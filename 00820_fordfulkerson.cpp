#include <bits/stdc++.h>

using namespace std;

int n,s,t,parent[100],graph[100][100];
bitset<100> visited;

int flow(int s,int t,int mmin)
{
	visited[s] = true;
	if(s == t)	return mmin;
	for(int i = 0;i < n;i++)
	{
		if(!visited[i] && graph[s][i] > 0) if(int f = flow(i,t,min(mmin,graph[s][i])))
		{
			graph[s][i] -= f,graph[i][s] += f;
			return f;
		}
	}
	return 0;
}
int maxflow()
{
	int ans = 0,f;
	visited.reset();
	while(f = flow(s,t,INT_MAX))	ans += f,visited.reset();
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	int TC = 0,c,u,v,w;
	while(true)
	{
		scanf("%d",&n);
		if(n == 0)	break;
		scanf("%d %d %d",&s,&t,&c);
		s--,t--;
		memset(graph,0,sizeof(graph));
		while(c--)
		{
			scanf("%d %d %d",&u,&v,&w);
			u--,v--;
			graph[u][v] += w;
			graph[v][u] += w;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",++TC,maxflow());
	}

	return 0;
}

