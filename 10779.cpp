#include <bits/stdc++.h>
#define NUMNODE 60

using namespace std;

int N,M,graph[NUMNODE][NUMNODE];
int source() {return 0;}
int target() {return 1;}
int bob(int n) {return n + 1;}
int fri(int n) {return n + M;}
typedef set<int>::iterator its;
bitset<NUMNODE> visited;

int maxflow(int s,int t,int minn)
{
	visited[s] = true;
	if(s == t)	return minn;
	int flow;
	for(int i = 0;i < 60;i++)
		if(!visited[i] && graph[s][i] && (flow = maxflow(i,t,min(minn,graph[s][i]))))
		{
			graph[s][i] -= flow; graph[i][s] += flow;
			return flow;
		}
	return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	int TC,n,in,ans,flow;
	set<int> has[10],exchangable[10];
	int num[10][30];
	scanf("%d",&TC);
	for(int x = 1;x <= TC;x++)
	{
		for(int i = 0;i < 10;i++)	has[i].clear(),exchangable[i].clear();
		scanf("%d %d",&N,&M);
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&in);
			}
		}
		ans = 0;
		while(true)
		{
			visited.reset();
			if((flow = maxflow(source(),target(),INT_MAX)) == 0)	break;
			ans += flow;
		}
		printf("Case #%d: %d\n",x,ans);
		puts("");
	}

	return 0;
}
