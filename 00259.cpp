#include <bits/stdc++.h>
#define src 36
#define sink 37
#define INF 1000000
#define V 38

using namespace std;

int graph[V][V],parent[V],x;
bitset<V> visited;

int node(char c)
{
	if(isdigit(c))	return c - '0';
	return c - 'A' + 10;
}
bool bfs()
{
	int u;
	visited.reset();
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while(!q.empty())
	{
		u = q.front(); q.pop();
		if(u == sink)	return true;
		for(int i = 0;i < V;i++)	if(graph[u][i] > 0 && !visited[i])
			q.push(i),parent[i] = u,visited[i] = true;
	}
	return false;
}
int maxflow()
{
	int u,v,w,x = 0;
	for(int i = 0;i < V;i++)
		x += graph[src][i];
	while(true)
	{
		visited.reset();
		if(!bfs())	break;
		w = INF;
		for(v = sink;v != src;v = parent[v])
			w = min(w,graph[parent[v]][v]);
		for(v = sink;v != src;v = parent[v])
		{
			u = parent[v];
			graph[u][v] -= w;
			graph[v][u] += w;
		}
		v = parent[sink];
		u = parent[v];
		x--;
	}
	return x;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,t,len;
	char s[1001];
	while(true)
	{
		if(feof(stdin))	break;
		memset(graph,0,sizeof(graph));
		while(gets(s))
		{
			if(s[0] == '\0')	break;
			len = strlen(s);
			n = node(s[0]);
			t = s[1] - '0';
			graph[src][n] += t;
			for(int i = 3;s[i] != ';';i++)
				graph[n][node(s[i])]++;
		}
		for(char i = '0';i <= '9';i++)	graph[node(i)][sink] = 1;
		int x = maxflow();
		if(x)	puts("!");
		else
		{
			for(int i = 0;i < 10;i++)
			{
				bool found = false;
				for(char j = 'A';j <='Z';j++)	if(graph[i][node(j)])
					printf("%c",j),found = true;
				if(!found)	printf("_");
			}
			printf("\n");
		}
	}

	return 0;
}
