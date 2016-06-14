#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool has(vector<int> v,int x)
{
	for(int i = 0;i < v.size();i++)	if(v[i] == x)	return true;
	return false;
}
int main()
{
//	freopen("in.txt","r",stdin);
	vector<int> graph[200];
	queue<int> q;
	int colour[200];
	int TC,n,p,t,u,v,ans,arr[2];
	bool is_bipartite;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)	graph[i].clear();
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&p);
			for(int j = 0;j < p;j++)
			{
				scanf("%d",&t);
				t--;
				if(t >= n)	continue;
				if(!has(graph[i],t))	graph[i].push_back(t);
				if(!has(graph[t],i))	graph[t].push_back(i);
			}
		}
		ans = 0;
		memset(colour,-1,sizeof(colour));
		for(int i = 0;i < n;i++)
		{
			if(colour[i] != -1)	continue;

			is_bipartite = true;
			while(!q.empty())	q.pop();
			q.push(i);
			colour[i] = 1;
			arr[0] = 0,arr[1] = 1;
			while(!q.empty())
			{
				u = q.front();
				q.pop();
				for(vector<int>::iterator j = graph[u].begin();j != graph[u].end();j++)
				{
					v = *j;
					if(colour[v] == -1)
						colour[v] = 1 - colour[u],arr[colour[v]]++,q.push(v);
					else if(colour[v] == colour[u])
						is_bipartite = false;
				}
			}
			if(is_bipartite)	ans += max(arr[0],arr[1]);
		}
//		printf("*** DEBUG ***\n");
//		for(int i = 0;i < n;i++)
//			printf("%d\t%d\n",i,colour[i]);
//		printf("*** DEBUG ***\n");
		printf("%d\n",ans);
	}

	return 0;
}
