#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > arr;
vector<vector<int> > graph;
bitset<30> visited;

bool fit(vector<int> a,vector<int> b)
{
	if(a.size() != b.size())	return false;
	for(int i = 0;i < a.size();i++)
		if(a[i] >= b[i])	return false;
	return true;
}
void dfs(int u,vector<int> &path,vector<int> &max_path)
{
	path.push_back(u + 1);
	if(max_path.size() < path.size())
	{
		max_path.clear();
		max_path.assign(path.begin(),path.end());
	}
	visited.set(u);
	for(vector<int>::iterator it = graph[u].begin();it < graph[u].end();it++)
	{
		if(!visited[*it]) dfs(*it,path,max_path);
	}
	visited.reset(u);
	path.pop_back();
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,x;
	vector<int> path,max_path;
	while(~scanf("%d %d",&n,&m))
	{
		arr.clear();
		for(int i = 0;i < n;i++)
		{
			vector<int> t;
			for(int i = 0;i < m;i++)
			{
				scanf("%d",&x);
				t.push_back(x);
			}
			sort(t.begin(),t.end());
			arr.push_back(t);
		}
		graph.assign(n,vector<int>());
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(i != j && fit(arr[i],arr[j]))
			graph[i].push_back(j);
		path.clear(); max_path.clear(); visited.reset();
		for(int i = 0;i < n;i++)
			dfs(i,path,max_path);
		printf("%d\n",max_path.size());
		copy(max_path.begin(),max_path.end(),ostream_iterator<int>(cout," "));
		printf("\n");
	}

	return 0;
}
