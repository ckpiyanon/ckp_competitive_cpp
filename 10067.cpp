#include <bits/stdc++.h>
#define W first
#define V second

using namespace std;
typedef pair<int,int> ii;

bitset<10000> available;
bitset<10000> visited;
int src,des;
int next(int n,bool inc,int col)
{
	int t = (int)pow(10,col);
	int x = (n / t) % 10;
	if(inc)
	{
		if(x < 9)	return n + t;
		return n - t*9;
	}
	if(x > 0)	return n - t;
	return n + t*9;
}
int bfs()
{
	priority_queue<ii,vector<ii>,greater<ii> > q;
	visited.reset();
	ii p;
	q.push(make_pair(0,src));
	while(!q.empty())
	{
		p = q.top();
		q.pop();
		if(!available[p.V])	continue;
		if(visited[p.V])	continue;
		if(p.V == des)	return p.W;
		visited[p.V] = true;
		for(int i = 0;i < 4;i++)	for(int j = 0;j < 2;j++)
		{
			int v = next(p.V,j,i);
			if(available[v] && !visited[v])	q.push(make_pair(p.W + 1,v));
		}
	}
	return -1;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,t,n,tmp;
	scanf("%d",&TC);
	while(TC--)
	{
		src = des = 0;
		for(int i = 0;i < 4;i++)	scanf("%d",&t),src *= 10,src += t;
		for(int i = 0;i < 4;i++)	scanf("%d",&t),des *= 10,des += t;
		scanf("%d",&n);
		available.reset();
		available.flip();
		while(n--)
		{
			tmp = 0;
			for(int i = 0;i < 4;i++)	scanf("%d",&t),tmp *= 10,tmp += t;
			available.set(tmp,false);
		}
		printf("%d\n",bfs());
	}

	return 0;
}
