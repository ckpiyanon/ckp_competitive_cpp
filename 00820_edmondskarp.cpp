#include <bits/stdc++.h>

using namespace std;

int n,s,t,parent[100],graph[100][100];
bitset<100> visited;

bool bfs()
{
	int u;
	visited.reset();
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		u = q.front(); q.pop();
		if(visited[u])	continue;
		visited[u] = true;
		if(u == t)	return true;
		for(int i = 0;i < n;i++) if(graph[u][i] > 0 && !visited[i])
			q.push(i),parent[i] = u;
	}
	return false;
}
int maxflow()
{
	int ans = 0,f,u;
	while(bfs())
	{
		f = INT_MAX;
		for(int v = t;v != s;v = parent[v])
			f = min(f,graph[parent[v]][v]);
		for(int v = t;v != s;v = parent[v])
		{
			u = parent[v];
			graph[u][v] -= f;
			graph[v][u] += f;
		}
		ans += f;
	}
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
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
