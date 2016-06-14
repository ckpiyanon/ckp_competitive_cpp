#include <bits/stdc++.h>
using namespace std;
int deg[101],n,m;
bitset<101> visited;
vector<vector<int> > graph(101);
bool first;
void dfs(int u)
{
	if(visited[u])	return;
	visited[u] = true;
	if(!first) printf(" ");
	first = false;
	printf("%d",u);
	for(vector<int>::iterator i = graph[u].begin();i < graph[u].end();i++)
	{
		deg[*i]--;
		if(deg[*i] == 0) dfs(*i);
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	int u,v;
	while(~scanf("%d %d",&n,&m) && n && m)
	{
		graph.assign(graph.size(),vector<int>());
		memset(deg,0,sizeof(deg));
		first = true;
		visited.reset();
		while(m--)
		{
			scanf("%d %d",&u,&v);
			graph[u].push_back(v);
			deg[v]++;
		}
		for(int i = 1;i <= n;i++) if(deg[i] == 0)
		{
			deg[i]--;
			dfs(i);
		}
	}
	return 0;
}
