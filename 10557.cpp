#include <bits/stdc++.h>
#define INF -1000000

using namespace std;

typedef vector<int> vi;

vector<vi> graph(100);
bool found;
int n,u,v,w,m;
vi dist(100),stp(100);
bitset<100> visited;

bool reachable(int u,int v)
{
	if(u == v)	return true;
	if(stp[u] <= 0)	return false;
	bool found = false;
	visited[u] = true;
	for(int i = 0;i < graph[v].size() && !found;i++)
		if(!visited[graph[v][i]] && reachable(v,graph[v][i]))	found = true;
	visited[u] = false;
	return found;
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(true)
	{
		scanf("%d",&n);
		if(n == -1)	break;
		graph = vector<vi>(n);
		dist.assign(100,0);
		stp.assign(100,INF);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&w),dist[i] = w;
			scanf("%d",&m);
			while(m--)
				scanf("%d",&v),graph[i].push_back(v-1);
		}
		stp[0] = 100;
		found = false;
		for(int i = 1;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				for(int k = 0;k < graph[j].size();k++)
				{
					if(stp[j] > 0)
						stp[graph[j][k]] = max(stp[graph[j][k]],stp[j] + dist[graph[j][k]]);
				}
			}
		}
		visited.reset();
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < graph[i].size();j++)
				if(stp[i] + dist[graph[i][j]] > stp[graph[i][j]] && reachable(0,graph[i][j])) found = true;
		}
		printf("%s\n",(found || stp[n-1] > 0) ? "winnable":"hopeless");
	}

	return 0;
}
