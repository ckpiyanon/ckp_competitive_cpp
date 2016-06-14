#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<vector<ii> > graph(26);
int stp(int u,int v)
{
	int w;
	bitset<26> visited;
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	pq.push(ii(0,u));
	ii e;
	while(!pq.empty())
	{
		e = pq.top();
		pq.pop();
		u = e.second;
		w = e.first;
		if(visited[u])	continue;
		visited[u] = true;
		if(u == v)	return w;
		for(int i = 0;i < graph[u].size();i++)
		{
			if(visited[graph[u][i].second])	continue;
			pq.push(ii(w + graph[u][i].first,graph[u][i].second));
		}
	}
	return 0;
}
int main()
{
//	freopen("in.txt","r",stdin);
	char s[101];
	int arr[2],len,x,ans,deg;
	while(gets(s))
	{
		if(strcmp(s,"deadend"))
		{
			len = strlen(s);
			graph[s[0]-'a'].push_back(ii(len,s[len-1]-'a'));
			graph[s[len-1]-'a'].push_back(ii(len,s[0]-'a'));
			continue;
		}
		x = 0;
		for(int i = 0;i < 26;i++)
			if(graph[i].size() % 2)	arr[x++] = i;
		ans = 0;
		for(int i = 0;i < 26;i++) for(int j = 0;j < graph[i].size();j++)
			ans += graph[i][j].first;
		ans /= 2;
		if(x == 2)	ans += stp(arr[0],arr[1]);
		printf("%d\n",ans);
		graph.assign(26,vector<ii>());
	}
	return 0;
}
