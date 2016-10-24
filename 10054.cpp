#include <bits/stdc++.h>

using namespace std;

int n,node,src,tar;
int path[1001];
int graph[50][50];

bool dfs(int v,int num)
{
	if(num-1 == n)
	{
		if(v != tar)	return false;
		for(int i = 0;i < n;i++)
			printf("%d %d\n",path[i]+1,path[i+1]+1);
		return true;
	}
	for(int i = 0;i < node;i++) if(graph[v][i])
	{
		graph[v][i]--;
		if(v != i)	graph[i][v]--;
		path[num] = i;
		if(dfs(i,num+1))	return true;
		graph[v][i]++;
		if(v != i)	graph[i][v]++;
	}
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	int TC,u,v;
	scanf("%d",&TC);
	for(int tc = 0;tc < TC;tc++)
	{
		scanf("%d",&n);
		node = 0;
		memset(graph,0,sizeof(graph));
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&u,&v);
			node = max(node,max(u,v));
			u--; v--;
			if(i == 0)	src = tar = u;
			graph[u][v]++;
			if(u != v)	graph[v][u]++;
		}
		if(tc)	printf("\n");
		printf("Case #%d\n",tc+1);
		path[0] = src;
		if(!dfs(src,1))	printf("some beads may be lost\n");
	}

	return 0;
}
