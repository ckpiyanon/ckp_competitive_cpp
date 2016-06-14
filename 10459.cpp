#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph(5001);
bitset<5001> visited;
int weight[5001];

int bfs(int u)
{
	int weight = 0,w;
	pair<int,int> p;
	queue<pair<int,int> > q;
	q.push(make_pair(u,0));
	visited.reset();
	while(!q.empty())
	{
		p = q.front();	q.pop();
		if(visited[p.first])	continue;
		u = p.first;	w = p.second;
		visited[u] = true;
		weight = max(weight,w);
		for(vector<int>::iterator it = graph[u].begin();it < graph[u].end();it++)
			if(!visited[*it])	q.push(make_pair(*it,w+1));
	}
	return weight;
}

int main()
{
	int n,m,x,mn,mx;
	while(~scanf("%d",&n))
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&x);
				graph[i].push_back(x-1);
			}
		}
		for(int i = 0;i < n;i++)
		{
			weight[i] = bfs(i);
			if(!i)	mx = mn = weight[i];
			else	mx = max(mx,weight[i]),mn = min(mn,weight[i]);
		}
		printf("Best Roots  :");
		for(int i = 0;i < n;i++)	if(weight[i] == mn)	printf(" %d",i+1);
		printf("\n");
		printf("Worst Roots :");
		for(int i = 0;i < n;i++)	if(weight[i] == mx)	printf(" %d",i+1);
		printf("\n");
	}

	return 0;
}
