#include <bits/stdc++.h>

using namespace std;
typedef pair<int,bool> edge;
int n,node,path[1001],cnt;
int weight[50][50];
void dfs(int u)
{
	for(int v = 0;v < node;v++) if(weight[u][v])
	{
		weight[u][v]--;
		weight[v][u]--;
		dfs(v);
	}
	path[cnt++] = u;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,u,v,src;
	bool is_euler;
	scanf("%d",&TC);
	for(int tc = 0;tc < TC;tc++)
	{
		scanf("%d",&n);
		node = 0;
		is_euler = true;
		memset(path,0,sizeof(path));
		memset(weight,0,sizeof(weight));
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&u,&v);
			node = max(node,max(u,v));
			u--; v--;
			if(i == 0)	src = u;
			path[u]++; path[v]++;
			weight[u][v]++;	weight[v][u]++;
		}
		if(tc)	printf("\n");
		printf("Case #%d\n",tc+1);
		for(int i = 0;i < node && is_euler;i++)
			is_euler = !(path[i] & 1);
		if(!is_euler)	printf("some beads may be lost\n");
		else
		{
			cnt = 0;
			dfs(src);
			for(int i = 1;i < cnt;i++)	printf("%d %d\n",path[i] + 1,path[(i + 1) % n] + 1);
		}
	}

	return 0;
}
