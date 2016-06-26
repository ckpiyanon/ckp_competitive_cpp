#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<vii> vv;

bitset<101> visited;
int n;

int dijkstra(vector<vv> &graph,int s,int t)
{
	priority_queue<iii,vector<iii>,greater<iii> > pq;
	int u,v,w;
	iii e;
	visited.reset();
	for(int i = 0;i < n;i++)
		for(vii::iterator it = graph[i][0].begin();it != graph[i][0].end();it++)
			pq.push(make_pair(make_pair(it->first,it->second),i));
	visited.set(0);
	while(!pq.empty())
	{
		e = pq.top();	pq.pop();
		u = e.first.second;
		if(visited[u])	continue;
		visited.set(u);
		if(u == t)	return e.first.first;
		for(int i = 0;i < n;i++)
			for(vii::iterator it = graph[i][u].begin();it != graph[i][u].end();it++)
				if(!visited[it->second])
				{
					w = it->first + e.first.first;
					if(e.second != i)	w += 60;
					pq.push(make_pair(make_pair(w,it->second),i));
				}
	}
	return -1;
}

int main()
{
	freopen("in.txt","r",stdin);
	vector<vv> graph(5);
	int t[5],k,u,v,w;
	char s[500],*tok;
	while(gets(s))
	{
		n = atoi(strtok(s," "));
		k = atoi(strtok(NULL," "));
		graph.assign(graph.size(),vv(101));
		gets(s);
		t[0] = atoi(strtok(s," "));
		for(int i = 1;i < n;i++)	t[i] = atoi(strtok(NULL," "));
		for(int i = 0;i < n;i++)
		{
			graph[i].assign(graph[i].size(),vii());
			gets(s);
			u = atoi(strtok(s," "));
			while(tok = strtok(NULL," "))
			{
				v = atoi(tok);
				graph[i][u].push_back(make_pair(t[i] * abs(v-u),v));
				graph[i][v].push_back(make_pair(t[i] * abs(v-u),u));
			}
		}
		w = dijkstra(graph,0,k);
		if(w == -1)	puts("IMPOSSIBLE");
		else	printf("%d\n",w);
	}
	return 0;
}
