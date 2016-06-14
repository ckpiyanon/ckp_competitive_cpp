#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph(300);
bitset<300> visited,colour;
bool dfs(int v,bool col)
{
	if(visited[v]) return col == colour[v];
	visited[v] = true;
	colour[v] = col;
	bool chk = true;
	for(vector<int>::iterator i = graph[v].begin();chk && i < graph[v].end();i++)
		chk = chk && dfs(*i,!col);
	return chk;
}
int main()
{
//	freopen("in.txt","r",stdin);
	bool chk;
	int n,u,v;
	while(~scanf("%d",&n) && n)
	{
		graph.assign(300,vector<int>());
		while(~scanf("%d %d",&u,&v) && u-- && v--)
			graph[u].push_back(v),graph[v].push_back(u);
		visited.reset();
		chk = true;
		for(int i = 0;i < n && chk;i++) if(!visited[i])
			chk = chk && dfs(i,true);
		puts(chk ? "YES":"NO");
	}

	return 0;
}
