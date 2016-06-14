#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

bitset<100000> visited,in;
vector<vi> graph(100000),rgraph(100000);
stack<int> st;
int n,comp[100000];

void dfs(int u)
{
	visited[u] = true;
	for(vi::iterator it = graph[u].begin();it < graph[u].end();it++)
		if(!visited[*it]) dfs(*it);
	st.push(u);
}
void dfs(int u,int num)
{
	visited[u] = true;
	comp[u] = num;
	for(vi::iterator it = rgraph[u].begin();it < rgraph[u].end();it++)
		if(!visited[*it]) dfs(*it,num);
}
int main()
{
	int TC,m,u,v;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&n,&m);
		graph.assign(n,vi());
		rgraph.assign(n,vi());
		while(!st.empty()) st.pop();
		while(m--)
		{
			scanf("%d %d",&u,&v); u--; v--;
			graph[u].push_back(v);
			rgraph[v].push_back(u);
		}
		visited.reset(); in.reset();
		for(int i = 0;i < n;i++) if(!visited[i]) dfs(i);
		visited.reset();
		m = 0;
		while(!st.empty())
		{
			u = st.top(); st.pop();
			if(!visited[u]) dfs(u,m++);
		}
		for(int i = 0;i < n;i++) for(vi::iterator it = graph[i].begin();it < graph[i].end();it++)
			if(comp[*it] != comp[i]) in[comp[*it]] = true;
		u = 0;
		for(int i = 0;i < m;i++)
			u += !in[i];
		printf("%d\n",u);
	}

	return 0;
}
