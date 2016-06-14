#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int p[1000],set_size;
void set_init(int n)
{
	for(int i = 0;i < 1000;i++)	p[i] = i;
	set_size = n;
}
int set_find(int n)
{
	int x = n,t;
	while(x != p[x])	x = p[x];
	while(n != p[n])
	{
		t = p[n];
		p[n] = x;
		n = t;
	}
	return x;
}
void set_merge(int a,int b)
{
	int pa = set_find(a),pb = set_find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		set_size--;
	}
}
bool set_same(int a,int b) {return set_find(a) == set_find(b);}

int main()
{
//	freopen("in.txt","r",stdin);
	vector<iii> graph,ans;
	int TC,n,w;
	char s[101];
	scanf("%d",&TC);
	for(int tc = 1;tc <= TC;tc++)
	{
		scanf("%d",&n);
		set_init(n);
		graph.clear(); ans.clear();
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
			{
				scanf("%s",s);
				strtok(s,", ");
				if(w = atoi(s))	graph.push_back(iii(w,ii(i,j)));
			}
		sort(graph.begin(),graph.end());
		for(vector<iii>::iterator it = graph.begin();it != graph.end() && set_size > 1;it++)
		{
			if(set_same(it->second.first,it->second.second))	continue;
			ans.push_back(*it);
			set_merge(it->second.first,it->second.second);
		}
		printf("Case %d:\n",tc);
		for(vector<iii>::iterator it = ans.begin();it != ans.end();it++)
			printf("%c-%c %d\n",it->second.first + 'A',it->second.second + 'A',it->first);
	}

	return 0;
}
