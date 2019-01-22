#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph(5001);
int weight[5001];

void dfs(int u,int w)
{
	weight[u] = w;
	for(vector<int>::iterator it = graph[u].begin();it < graph[u].end();it++)
		if(weight[*it] == -1)
			dfs(*it,w + 1);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	set<int> best1,best2,worst;
	int n,m,x,mn1,mn2,mx;
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
		best1.clear();
		best2.clear();
		worst.clear();

		memset(weight,-1,sizeof(weight));
		dfs(0,0);
		x = 0;
		for(int i = 1;i < n;i++)
			if(weight[x] < weight[i])
				x = i;

		memset(weight,-1,sizeof(weight));
		dfs(x,0);
		x = 0;
		for(int i = 0;i < n;i++)
			if(weight[x] < weight[i])
				x = i;
		mx = weight[x];
		mn1 = mn2 = mx / 2;
		if(mx & 1)	mn2++;
		for(int i = 0;i < n;i++)
		{
			if(weight[i] == mx)	worst.insert(i);
			if(weight[i] == mn1 || weight[i] == mn2)	best1.insert(i);
		}

		memset(weight,-1,sizeof(weight));
		dfs(x,0);
		for(int i = 0;i < n;i++)
		{
			if(weight[i] == mx)	worst.insert(i);
			if(weight[i] == mn1 || weight[i] == mn2)	best2.insert(i);
		}

		printf("Best Roots  :");
		for(set<int>::iterator it = best1.begin();it != best1.end();it++)
			if(best2.find(*it) != best2.end())	printf(" %d",*it + 1);
		printf("\n");

		printf("Worst Roots :");
		for(set<int>::iterator it = worst.begin();it != worst.end();it++)
			printf(" %d",*it + 1);
		printf("\n");
	}

	return 0;
}
