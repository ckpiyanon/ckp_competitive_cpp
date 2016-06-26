#include <bits/stdc++.h>
#define TOTAL first
#define MAX second

using namespace std;
typedef pair<int,int> ii;
bitset<10000> visited;

void dijkstra(vector<vector<ii> > &graph,vector<int> &stp,int s)
{
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	visited.reset();
	pq.push(ii(0,s));
	ii e;
	while(!pq.empty())
	{
		e = pq.top(); pq.pop();
		if(visited[e.second])	continue;
		visited.set(e.second,true);
		stp[e.second] = e.first;
		for(vector<ii>::iterator it = graph[e.second].begin();it != graph[e.second].end();it++)
			if(!visited[it->second])	pq.push(ii(e.first + it->first,it->second));
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,u,v,c,n,m,s,t,p,ans;
	vector<vector<ii> > graph(10000),graphr(10000);
	vector<int> stp,stpr;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
		s--,t--;
		graph.assign(n,vector<ii>());
		graphr.assign(n,vector<ii>());
		stp.assign(n,-1); stpr.assign(n,-1);
		while(m--)
		{
			scanf("%d %d %d",&u,&v,&c);
			graph[u-1].push_back(ii(c,v-1));
			graphr[v-1].push_back(ii(c,u-1));
		}
		dijkstra(graph,stp,s);
		dijkstra(graphr,stpr,t);
		ans = -1;
		for(int k = 0;k < n;k++) for(vector<ii>::iterator it = graph[k].begin();it != graph[k].end();it++)
		{
			v = it->second;
			if(stp[k] != -1 && stpr[v] != -1 && it->first + stp[k] + stpr[v] <= p)
				ans = max(ans,it->first);
		}
		printf("%d\n",ans);
	}

	return 0;
}
