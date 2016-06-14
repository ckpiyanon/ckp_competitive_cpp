#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
vector<vector<ii> > graph(20000);
int n,m,s,t,w[20000];
bitset<20000> v;
priority_queue<ii,vector<ii>,greater<ii> > pq;

void dijkstra()
{
	v.reset();
	if(!pq.empty())	pq.pop();
	ii tmp;
	int tw,ti;
	pq.push(ii(0,s));
	while(true && !pq.empty())
	{
		tmp = pq.top();
		pq.pop();
		ti = tmp.second;
		tw = tmp.first;
		if(v[ti])	continue;
		v[ti] = true;
		w[ti] = tw;
		for(int i = 0;i < graph[ti].size();i++) if(!v[graph[ti][i].second])
			pq.push(ii(tw + graph[ti][i].first,graph[ti][i].second));
	}
}

int main()
{
	int TC,a,b,c;
	scanf("%d",&TC);
	for(int TC_ = 1;TC_ <= TC;TC_++)
	{
		memset(w,255,sizeof(w));
		scanf("%d %d %d %d",&n,&m,&s,&t);
		for(int i = 0;i < graph.size();i++)	graph[i].clear();
		for(int i = 0;i < m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			graph[a].push_back(ii(c,b));
			graph[b].push_back(ii(c,a));
		}
		printf("Case #%d: ",TC_);
		dijkstra();
		if(w[t] == -1)	printf("unreachable\n");
		else			printf("%d\n",w[t]);
	}

	return 0;
}
