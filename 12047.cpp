#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#include <functional>

using namespace std;
typedef pair<int,int> ii;
bitset<10000> vi;
vector<vector<ii> > graph(10000);
vector<ii> ans;
int n,m,s,t,p;

bool cmp(ii a,ii b) {return a > b;}
void dfs(int u,int weight,int highest)
{
	printf("** VISITED NODE %d **\n",u);
	if(vi[u])	return;
	if(u == t)
	{
		printf("%d %d\n",weight,highest);
		ans.push_back(ii(weight,highest));
		return;
	}
	vi[u] = true;
	for(int i = 0;i < graph[u].size();i++)
	{
		ii t = graph[u][i];
		dfs(t.first,weight + t.second,max(highest,t.second));
	}
	vi[u] = false;
}

int main()
{
	freopen("in.txt","r",stdin);
	int TC,u,v,c;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
		s--,t--;
		for(int i = 0;i < n;i++)	graph[i].clear();
		ans.clear(); vi.reset();
		for(int i = 0;i < m;i++)
		{
			scanf("%d %d %d",&u,&v,&c);
			graph[u-1].push_back(ii(v-1,c));
		}
		dfs(s,0,0);
		sort(ans.begin(),ans.end(),cmp);
		int i = 0;
		while(i < ans.size() && ans[i].first > p)	i++;
		for(int j = 0;j < ans.size();j++)
			printf("%d %d\n",ans[i].first,ans[i].second);
		printf("\n\n");
		/*if(i == ans.size())	printf("-1\n");
		else				printf("%d\n",ans[i].second);*/
	}

	return 0;
}
