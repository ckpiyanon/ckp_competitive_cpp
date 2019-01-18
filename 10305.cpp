#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	vector<vector<int> > graph;
	vector<int> deg;
	queue<int> q;
	int n,m,u,v;
	while(scanf("%d %d",&n,&m),n != 0 || m != 0)
	{
		graph.assign(n,vector<int>());
		deg.assign(n,0);
		while(m--)
		{
			scanf("%d %d",&u,&v);
			graph[u-1].push_back(v-1);
			deg[v-1]++;
		}
		q = queue<int>();
		for(int i = 0;i < n;i++) if(!deg[i])
			q.push(i);
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			for(vector<int>::iterator it = graph[u].begin();it < graph[u].end();it++)
				if(--deg[*it] == 0)
					q.push(*it);
			printf("%d%c",u + 1,q.empty() ? '\n':' ');
		}
	}

	return 0;
}
