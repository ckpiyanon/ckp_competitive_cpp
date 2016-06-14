#include <bits/stdc++.h>
#define src 0
#define tar 99
#define person(n) (n + 6)
#define V 100

using namespace std;

int N,M,graph[V][V];
bitset<V> visited;

int tshirt(string s)
{
	if(s == "XS")	return 1;
	if(s == "S")	return 2;
	if(s == "M")	return 3;
	if(s == "L")	return 4;
	if(s == "XL")	return 5;
	if(s == "XXL")	return 6;
	return 0;
}
int flow(int s,int t,int mmin)
{
	visited[s] = true;
	if(s == t)	return mmin;
	for(int i = 0;i < V;i++)
	{
		if(!visited[i] && graph[s][i] > 0)
		{
			if(int f = flow(i,t,min(mmin,graph[s][i])))
			{
				graph[s][i] -= f;
				graph[i][s] += f;
				return f;
			}
		}
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,f,t;
	char sz[4];
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&N,&M);
		N /= 6;
		memset(graph,0,sizeof(graph));
		for(int i = 1;i <= 6;i++)	graph[src][i] = N;
		for(int i = 1;i <= M;i++)
		{
			scanf("%s",sz);
			graph[tshirt(sz)][person(i)] = 1;
			scanf("%s",sz);
			graph[tshirt(sz)][person(i)] = 1;
			graph[person(i)][tar] = 1;
		}
		f = 0;
		visited.reset();
		while(t = flow(src,tar,INT_MAX))
			f += t,visited.reset();
		printf("%s\n",f == M ? "YES":"NO");
	}

	return 0;
}
