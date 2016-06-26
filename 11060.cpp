#include <bits/stdc++.h>

using namespace std;

map<string,int> bev;
vector<vector<int> > graph(100);
vector<string> arr;
bitset<100> visited;
int ind[100];

void play(int u)
{
	printf(" %s",arr[u].c_str());
	visited.set(u,true);
	for(vector<int>::iterator it = graph[u].begin();it != graph[u].end();it++)
		ind[*it]--;
	for(int i = 0;i < arr.size();i++)
		if(ind[i] == 0 && !visited[i])	play(i);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,u,v,TC = 0;
	char s[101],s0[101];
	while(~scanf("%d",&n))
	{
		bev.clear();
		arr.clear();
		for(int i = 0;i < n;i++)
		{
			scanf("%s",s);
			bev.insert(make_pair(string(s),i));
			arr.push_back(string(s));
		}
		scanf("%d",&m);
		memset(ind,0,sizeof(ind));
		graph.assign(100,vector<int>());
		while(m--)
		{
			scanf("%s %s",s,s0);
			u = bev[string(s)];
			v = bev[string(s0)];
			ind[v]++;
			graph[u].push_back(v);
		}
		for(int i = 0;i < n;i++) if(ind[i] == 0) {u = i; break;}
		printf("Case #%d: Dilbert should drink beverages in this order:",++TC);
		visited.reset();
		play(u);
		printf(".\n\n");
	}

	return 0;
}
