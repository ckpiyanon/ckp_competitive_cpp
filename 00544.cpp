#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int numcity;
map<string,int> ma;

int getnum(string s)
{
	map<string,int>::iterator it = ma.find(s);
	if(it == ma.end())	return ma[s] = numcity++;
	return it->second;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w+",stdout);
	int m,n,x,TC = 0,graph[200][200];
	char s1[31],s2[31];
	string ss1,ss2;
	while(~scanf("%d %d",&m,&n) && m && n)
	{
		ma.clear();
		memset(graph,-1,sizeof(graph));
		numcity = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%s %s %d",s1,s2,&x);
			ss1 = string(s1); ss2 = string(s2);
			graph[getnum(ss1)][getnum(ss2)] = graph[getnum(ss2)][getnum(ss1)] = x;
		}
		for(int k = 0;k < numcity;k++) for(int i = 0;i < numcity;i++)
			if(graph[i][k] != -1) for(int j = 0;j < numcity;j++)
				if(graph[k][j] != -1)
					graph[i][j] = max(min(graph[i][k],graph[k][j]),graph[i][j]);
		scanf("%s %s",s1,s2);
		printf("Scenario #%d\n%d tons\n\n",++TC,graph[getnum(s1)][getnum(s2)]);
	}

	return 0;
}
