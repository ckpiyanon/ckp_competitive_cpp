#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<vi> graph(310);
bitset<310> visited;
char s[10001];
int parent[310],dist[310];

void stp(int u,int v)
{
	memset(parent,-1,sizeof(parent));
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	dist[u] = 0;
	q.push(u);
	while(!q.empty())
	{
		u = q.front(); q.pop();
		for(vector<int>::iterator i = graph[u].begin();i < graph[u].end();i++)
		{
			if(dist[*i] == -1 || dist[*i] > dist[u] + 1)
			{
				parent[*i] = u;
				dist[*i] = dist[u] + 1;
				q.push(*i);
			}
		}
	}
}
void print_path(int v)
{
	if(parent[v] == -1)	printf("%d",v);
	else
	{
		print_path(parent[v]);
		printf(" %d",v);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,u,v;
	char *tok;
	while(~scanf("%d",&n))
	{
		graph.assign(graph.size(),vi());
		for(int i = 0;i < n;i++)
		{
			scanf("%s",s);
			u = atoi(strtok(s,"-"));
			tok = strtok(strtok(NULL,"-"),",");
			while(tok)
			{
				v = atoi(tok);
				graph[u].push_back(v);
				tok = strtok(NULL,",");
			}
		}
		scanf("%d",&n);
		printf("-----\n");
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&u,&v);
			stp(u,v);
			if(parent[v] == -1)	printf("connection impossible");
			else	print_path(v);
			printf("\n");
		}
	}

	return 0;
}
