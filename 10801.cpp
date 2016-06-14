#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

bitset<100> visited;
vector<vii> graph(100);
char str[1001];

bool has_path(int u,int v)
{
	if(u == v)	return true;
	visited[u] = true;
	for(vii::iterator it = graph[u].begin();it < graph[u].end();it++)
	{
		if(!visited[it->second] && has_path(it->second,v))	return true;
	}
	return false;
}
int dijkstra(int u,int v)
{
	int w;
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	ii e;
	visited.reset();
	pq.push(ii(0,u));
	while(!pq.empty())
	{
		e = pq.top();	pq.pop();
		if(visited[e.second])	continue;
		u = e.second;
		w = e.first;
		if(u == v)	return w;
		visited[u] = true;
		for(vii::iterator it = graph[u].begin();it < graph[u].end();it++)
		{
			if(visited[it->second])	continue;
			pq.push(ii(w + it->first,it->second));
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	char *tok;
	int t[100],n,k,u,v;
	while(gets(str))
	{
		graph.assign(graph.size(),vii());
		n = atoi(strtok(str," "));
		k = atoi(strtok(NULL," "));
		gets(str);
		t[0] = atoi(strtok(str," "));
		for(int i = 1;i < n;i++)
			t[i] = atoi(strtok(NULL," "));
		for(int i = 0;i < n;i++)
		{
			gets(str);
			tok = strtok(str," ");
			u = atoi(tok);
			while(tok = strtok(NULL," "))
			{
				v = atoi(tok);
				graph[u].push_back(ii(t[i],v));
				graph[v].push_back(ii(t[i],u));
				u = v;
			}
		}
		visited.reset();
		if(!has_path(0,k))	printf("IMPOSSIBLE\n");
		else				printf("%d\n",dijkstra(0,k));
	}

	return 0;
}
