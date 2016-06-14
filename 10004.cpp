#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph(200);
int colour[200];
bool check(int u,int col)
{
	bool chk = true;
	colour[u] = col;
	for(int i = 0;i < graph[u].size() && chk;i++)
	{
		int node = graph[u][i];
		if(colour[node] == -1)
			chk &= check(node,!col);
		else if(colour[node] == colour[u])
			return false;
	}
	return chk;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int N,n,u,v;
	char ans[][5] = {"NOT ",""};
	bool bicolourable;
	while(true)
	{
		scanf("%d",&N);
		if(N == 0)	break;
		scanf("%d",&n);
		memset(colour,-1,sizeof(colour));
		for(int i = 0;i < 200;i++)	graph[i].clear();
		bicolourable = true;
		while(n--)
		{
			scanf("%d %d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for(int i = 0;i < N && bicolourable;i++) if(colour[i] == -1)
			bicolourable &= check(i,0);	/// 1 for blue, 0 for red
		printf("%sBICOLORABLE.\n",ans[bicolourable]);
	}

	return 0;
}
