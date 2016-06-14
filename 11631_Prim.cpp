#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main()
{
//	freopen("in.txt","r",stdin);
	vector<vii> graph(200000);
	bitset<200000> visited;
	priority_queue<ii,vector<ii>,greater<ii> > q;
	int m,n,x,y,z,total;
	while(true)
	{
		scanf("%d %d",&m,&n);
		if(m == 0 && n == 0)	break;
		for(int i = 0;i < m;i++)	graph[i].clear();
		while(!q.empty())	q.pop();
		visited.reset();
		total = 0;
		while(n--)
		{
			scanf("%d %d %d",&x,&y,&z);
			graph[x].push_back(make_pair(z,y));
			graph[y].push_back(make_pair(z,x));
			total += z;
		}
		n = 0;
		visited[0] = true;
		for(vii::iterator i = graph[0].begin();i != graph[0].end();i++)
			q.push(*i);
		while(!q.empty())
		{
			ii u = q.top();
			q.pop();
			if(visited[u.Y])
				continue;
			visited[u.Y] = true;
			n += u.X;
			for(vii::iterator i = graph[u.Y].begin();i != graph[u.Y].end();i++)
				if(!visited[i->Y])	q.push(*i);
		}
		printf("%d\n",total - n);
	}

	return 0;
}
