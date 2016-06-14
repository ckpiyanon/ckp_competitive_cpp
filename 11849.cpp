#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	unordered_set<int> s;
	int n,m,t;
	while(scanf("%d %d",&n,&m) != EOF && n && m)
	{
		s.clear();
		while(n--)	scanf("%d",&t),s.insert(t);
		while(m--)
		{
			scanf("%d",&t);
			if(s.find(t) != s.end())	n++;
		}
		printf("%d\n",n+1);
	}

	return 0;
}
