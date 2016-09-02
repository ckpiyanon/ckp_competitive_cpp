#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> graph(400);
map<string,int> ma;
priority_queue<ii,vector<ii>,greater<ii> > pq;
bitset<400> visited;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,u,v,w,ans;
	char s1[101],s2[101];
	while(true)
	{
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0)	break;
		graph.assign(graph.size(),vii());
		ma.clear();
		while(!pq.empty())	pq.pop();
		for(int i = 0;i < n;i++)	scanf("%s",s1),ma[s1] = i;
		while(m--)
		{
			scanf("%s %s %d",s1,s2,&w);
			u = ma[s1],v = ma[s2];
			graph[u].push_back(ii(w,v));
			graph[v].push_back(ii(w,u));
		}
		scanf("%s",s1); u = ma[s1];
		pq.push(ii(0,u));
		visited.reset();
		ans = 0;
		while(!pq.empty())
		{
			ii e = pq.top(); pq.pop();
			if(visited[e.second])	continue;
			visited.set(e.second,true);
			ans += e.first;
			for(vii::iterator it = graph[e.second].begin();it != graph[e.second].end();it++)
				if(!visited[it->second])    pq.push(*it);
		}
		for(int i = 0;i < n && ans >= 0;i++)
			if(!visited[i]) ans = -1;
		if(ans == -1)   puts("Impossible");
		else    printf("%d\n",ans);
	}

	return 0;
}
