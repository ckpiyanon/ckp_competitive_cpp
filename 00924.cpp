#include <bits/stdc++.h>
#define V first
#define W second
using namespace std;

vector<vector<int> > graph(2500);
int level[2500];
bitset<2500> visited;
typedef pair<int,int> ii;
void bfs(int u)
{
	queue<ii> q;
	ii p;
	q.push(make_pair(u,0));
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		if(visited[p.V])	continue;
		level[p.V] = p.W;
		visited[p.V] = true;
		for(int i = 0;i < graph[p.V].size();i++)
			q.push(make_pair(graph[p.V][i],p.W + 1));
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int E,n,u,*v,mm,nn;
	scanf("%d",&E);
	for(int i = 0;i < E;i++)
	{
		scanf("%d",&n);
		while(n--)	scanf("%d",&u),graph[i].push_back(u);
	}
	scanf("%d",&n);
	while(n--)
	{
		memset(level,0,sizeof(level));
		scanf("%d",&u);
		visited.reset();
		bfs(u);
		mm = -1;
		for(int i = 0;i < E;i++)	mm = max(mm,level[i]);
//		printf("*** %d\n",mm);
		v = new int[mm + 1];
		memset(v,0,sizeof(int) * (mm + 1));
		for(int i = 0;i < E;i++)	v[level[i]]++;
		nn = 0;
		for(int i = 1;i <= mm;i++)
			if(v[i] > nn)	u = i,nn = v[i];
		if(nn == 0)	printf("0\n");
		else		printf("%d %d\n",nn,u);
		delete[] v;
	}

	return 0;
}
