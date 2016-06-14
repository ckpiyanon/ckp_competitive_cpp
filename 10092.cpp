#include <bits/stdc++.h>
#define src 0
#define prob(n) n
#define cat(n) (n + np)
#define tar (1 + np + nk)
#define V 1100

using namespace std;

int graph[V][V];
int nk,np,N;
bitset<V> visited;

int flow(int s,int t,int mmin)
{
    visited[s] = true;
    if(s == t)	return mmin;
    for(int i = 0;i < N;i++)
	{
		if(!visited[i] && graph[s][i] > 0) if(int f = flow(i,t,min(mmin,graph[s][i])))
		{
			graph[s][i] -= f;
			graph[i][s] += f;
			return f;
		}
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,t,all;
	while(true)
	{
		scanf("%d %d",&nk,&np);
		if(nk == 0 && np == 0)	break;
		N = nk + np + 2;
		memset(graph,0,sizeof(graph));
		all = 0;
		for(int i = 1;i <= nk;i++)
		{
			scanf("%d",&t);
			all += t;
			graph[src][cat(i)] = t;
		}
		for(int i = 1;i <= np;i++)
		{
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&t);
				graph[cat(t)][prob(i)] = 1;
			}
			graph[prob(i)][tar] = 1;
		}
		n = 0;
		visited.reset();
		while(t = flow(src,tar,INT_MAX))	n += t,visited.reset();
		printf("%d\n",n == all);
		if(n == all)
		{
			for(int i = 1;i <= nk;i++)
			{
				bool printed = false;
				for(int j = 1;j <= np;j++)
				{
					if(graph[prob(j)][cat(i)])
					{
						if(printed)	printf(" ");
						printed = true;
						printf("%d",j);
					}
				}
				printf("\n");
			}
		}
	}

	return 0;
}
