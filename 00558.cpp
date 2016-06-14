#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<iii> viii;

int main()
{
	char ans[][21] = {"not possible","possible"};
	int TC,n,m,u,v,w,has;
	vi dist(1000);
	viii edges;
	iii edge;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&n,&m);
		edges.clear();
		dist.assign(1000,INF);
		dist[0] = 0;
		for(int i = 0;i < m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			edges.push_back(iii(w,ii(u,v)));
		}
		for(int i = 1;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				edge = edges[j];
				u = edge.second.first;
				v = edge.second.second;
				w = edge.first;
				dist[v] = min(dist[v],dist[u] + w);
			}
		}
		has = 0;
		for(int i = 0;i < m && !has;i++)
		{
			edge = edges[i];
			u = edge.second.first;
			v = edge.second.second;
			w = edge.first;
			if(dist[v] > dist[u] + w)
				has = 1;
		}
		puts(ans[has]);
	}

	return 0;
}
