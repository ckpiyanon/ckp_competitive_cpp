#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	vector<vector<pair<int,int> > > graph;
	vector<int> arr;
	int m,n,x,u;
	while(~scanf("%d %d",&m,&n))
	{
		graph = vector<vector<pair<int,int> > >(n);
		for(int k = 0;k < m;k++)
		{
			arr.clear();
			scanf("%d",&x);
			for(int i = 0;i < x;i++)
			{
				scanf("%d",&u);
				arr.push_back(u-1);
			}
			for(int i = 0;i < x;i++)
			{
				scanf("%d",&u);
				graph[arr[i]].push_back(make_pair(k,u));
			}
		}
		printf("%d %d\n",n,m);
		for(int k = 0;k < n;k++)
		{
			printf("%d",graph[k].size());
			for(int i = 0;i < graph[k].size();i++)
				printf(" %d",graph[k][i].first + 1);
			printf("\n");
			u = true;
			for(int i = 0;i < graph[k].size();i++)
			{
				if(!u)	printf(" ");
				u = false;
				printf("%d",graph[k][i].second);
			}
			printf("\n");
		}
	}

	return 0;
}
