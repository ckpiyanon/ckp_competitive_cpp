#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> graph[30];
int v[30];

void bfs(int node)
{
	queue<int> q;
	for(int i = 0;i < 30;i++)	v[i] = 2000000000;
	q.push(node);
	v[node] = 0;
	while(!q.empty())
	{
        node = q.front();
        q.pop();
        for(int i = 0;i < graph[node].size();i++)
			if(v[graph[node][i]] > v[node] + 1)
				v[graph[node][i]] = v[node] + 1,q.push(graph[node][i]);
	}
}

int main()
{
	map<int,int> keys;
	int N,a,b,nN,ans,TC = 0;
	while(true)
	{
        scanf("%d",&N);
        if(N == 0)	break;
        nN = 0;
        keys.clear();
        for(int i = 0;i < 30;i++)	graph[i].clear();
        for(int i = 0;i < N;i++)
		{
			scanf("%d %d",&a,&b);
			if(keys.find(a) == keys.end())	keys[a] = nN++;
			if(keys.find(b) == keys.end())	keys[b] = nN++;
			graph[keys.at(a)].push_back(keys.at(b));
			graph[keys.at(b)].push_back(keys.at(a));
		}
		while(true)
		{
			scanf("%d %d",&a,&b);
			if(!a && !b)	break;
			bfs(keys[a]);
			ans = 0;
			for(int i = 0;i < nN;i++)	if(v[i] > b)	ans++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++TC,ans,a,b);
		}
	}

	return 0;
}
