#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
char inp[200];
int node[26];
bool visited[26];
vector<vector<int> > graph;

int dfs(int u)
{
	int mx = 0;
	for(vector<int>::iterator it = graph[u].begin();it < graph[u].end();it++) if(!visited[*it])
	{
		visited[*it] = true;
		mx = max(mx,dfs(*it));
		visited[*it] = false;
	}
	return mx + node[u];
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC = atoi(gets(inp)),u,v,w,len,tok;
	char su[10],sv[50];
	gets(inp);
	while(TC--)
	{
		graph.assign(26,vector<int>());
		memset(node,-1,sizeof(node));
		memset(visited,0,sizeof(visited));
		while(gets(inp) && strlen(inp))
		{
			tok = sscanf(inp,"%s %d %s",su,&w,&sv);
			u = su[0] - 'A';
			node[u] = w;
			if(tok == 3)
			{
				len = strlen(sv);
				for(int i = 0;i < len;i++)
				{
					v = sv[i] - 'A';
					graph[v].push_back(u);
				}
			}
		}
		int mx = 0;
		for(int i = 0;i < 26;i++) if(node[i] > -1)
		{
			mx = max(mx,dfs(i));
		}
		printf("%d\n",mx);
		if(TC)	printf("\n");
	}

	return 0;
}
