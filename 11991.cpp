#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	vector<vector<int> > graph(1000001);
	int m,n,u,v,mm;
	while(~scanf("%d %d",&n,&m))
	{
		graph.assign(graph.size(),vector<int>());
		mm = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&u);
			graph[u].push_back(i);
			mm = max(mm,u);
		}
		while(m--)
		{
			scanf("%d %d",&v,&u);
			if(graph[u].size() < v)	printf("0\n");
			else	printf("%d\n",graph[u][v-1]);
		}
	}

	return 0;
}
