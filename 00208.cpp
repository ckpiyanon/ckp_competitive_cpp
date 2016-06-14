#include <bits/stdc++.h>

using namespace std;

vector<int> snapshot;
bitset<21> visited;
int n,num_path;
bool graph[21][21],dp[21][21];

void dfs(int u)
{
	snapshot.push_back(u);
	if(u == n)
	{
		for(int i = 0;i < snapshot.size();i++)
			printf("%d%c",snapshot[i],i < snapshot.size() - 1 ? ' ':'\n');
		num_path++;
	}
	else
	{
		visited[u] = true;
		for(int i = 1;i < 21;i++)
			if(graph[u][i] && !visited[i])	dfs(i);
		visited[u] = false;
	}
	snapshot.pop_back();
}
int main()
{
//	freopen("in.txt","r",stdin);
	int u,v,TC = 0;
	while(scanf("%d",&n) != EOF)
	{
		printf("CASE %d:\n",++TC);
		memset(graph,false,sizeof(graph));
		visited.reset();
		while(true)
		{
			scanf("%d %d",&u,&v);
			if(u == 0 && v == 0)	break;
			graph[u][v] = graph[v][u] = true;
		}
		memcpy(dp,graph,sizeof(graph));
		for(int k = 0;k < 21;k++) for(int i = 0;i < 21;i++) for(int j = 0;j < 21;j++)
			dp[i][j] |= dp[i][k] & dp[k][j];
		num_path = 0;
		if(dp[1][n])
		{
			snapshot.clear();
			dfs(1);
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n",num_path,n);
	}

	return 0;
}
