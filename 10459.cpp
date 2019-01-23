#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph(5001);
vector<int> path;
set<int> best,worst;
int weight[5001],max_len,node_end;

void dfs(int uu,int u,int w,bool find_node)
{
	weight[u] = path.size();
	path.push_back(u);
	if(weight[u] > max_len)
	{
		node_end = u;
		max_len = weight[u];
		if(find_node)
		{
			best.clear();
			worst.clear();
		}
	}
	if(find_node && weight[u] == max_len)
	{
		worst.insert(uu);
		worst.insert(u);
		best.insert(path[max_len / 2]);
		if(max_len & 1)	best.insert(path[(max_len / 2) + 1]);
	}
	for(vector<int>::iterator it = graph[u].begin();it < graph[u].end();it++)
		if(weight[*it] == -1)	dfs(uu,*it,w + 1,find_node);
	path.pop_back();
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,x;
	while(~scanf("%d",&n))
	{
		graph.assign(n,vector<int>());
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&x);
				graph[i].push_back(x-1);
			}
		}
		best.clear(); worst.clear(); path.clear();
		max_len = -1;
		memset(weight,-1,sizeof(weight));
		dfs(0,0,0,false);

		best.clear(); worst.clear(); path.clear();
		max_len = -1;
		memset(weight,-1,sizeof(weight));
		dfs(node_end,node_end,0,true);

		memset(weight,-1,sizeof(weight));
		dfs(node_end,node_end,0,true);

		printf("Best Roots  :");
		for(set<int>::iterator it = best.begin();it != best.end();it++)
			printf(" %d",*it + 1);
		printf("\n");

		printf("Worst Roots :");
		for(set<int>::iterator it = worst.begin();it != worst.end();it++)
			printf(" %d",*it + 1);
		printf("\n");
	}

	return 0;
}
