#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int colour[200],cnt[2];
vvi graph(200);
bool isb;

void dfs(int u,int c)
{
	colour[u] = c;
	cnt[c]++;
	for(vi::iterator it = graph[u].begin();it != graph[u].end() && isb;it++)
	{
		if(colour[*it] == c)
		{
			isb = false;
			return;
		}
		if(colour[*it] == -1)	dfs(*it,!c);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,m,u,v,ans;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&n,&m);
		graph.assign(graph.size(),vi());
		while(m--)
		{
			scanf("%d %d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(colour,-1,sizeof(colour));
		ans = 0;
		isb = true;
		for(int i = 0;i < n && isb;i++)
			if(colour[i] == -1)
			{
				cnt[0] = cnt[1] = 0;
				dfs(i,0);
				ans += max(1,min(cnt[0],cnt[1]));
			}
		printf("%d\n",isb ? ans:-1);
	}

	return 0;
}
