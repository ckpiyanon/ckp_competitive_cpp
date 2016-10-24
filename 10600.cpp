#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> edge;
int uf_parent[100];
int uf_size;
int uf_find(int n)
{
	if(n == uf_parent[n])	return n;
	return uf_parent[n] = uf_find(uf_parent[n]);
}
bool uf_same(int a,int b) {return uf_find(a) == uf_find(b);}
void uf_merge(int a,int b)
{
	if(uf_same(a = uf_find(a),b = uf_find(b)))	return;
	uf_parent[a] = b;
	uf_size--;
}

vector<int> used;
vector<edge> graph;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,m,u,v,w,w0,w1;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&m,&n);
		graph.clear();
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			graph.push_back(edge(w,ii(u-1,v-1)));
		}
		sort(graph.begin(),graph.end());
		used.clear();
		w0 = 0;
		uf_size = m;
		for(int i = 0;i < m;i++)	uf_parent[i] = i;
		for(int i = 0;i < n;i++)
		{
			edge e = graph[i];
			if(uf_same(u = e.second.first,v = e.second.second))	continue;
			used.push_back(i);
			w0 += e.first;
			uf_merge(u,v);
			if(uf_size == 1)	break;
		}
		w1 = INT_MAX;
		for(int k = 0;k < used.size();k++)
		{
			w = 0;
			uf_size = m;
			for(int i = 0;i < m;i++)	uf_parent[i] = i;
			for(int i = 0;i < n;i++)
			{
				if(i == used[k])	continue;
				edge e = graph[i];
				if(uf_same(u = e.second.first,v = e.second.second))	continue;
				w += e.first;
				uf_merge(u,v);
				if(uf_size == 1)
				{
					if(w1 > w)	w1 = w;
					break;
				}
			}
		}
		printf("%d %d\n",w0,w1);
	}

	return 0;
}
