#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	map<int,int> ma;
	map<int,int>::iterator it1,it2;
	int N,n,t;
	long long ans;
	pair<int,int> p1,p2;
	while(scanf("%d",&N) != EOF && N != 0)
	{
		ma.clear();
		ans = 0;
		while(N--)
		{
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&t);
				if(ma.find(t) == ma.end())	ma[t] = 1;
				else	ma[t]++;
			}
			it1 = ma.begin();
			it2 = ma.end(); it2--;
			p1 = *it1,p2 = *it2;
			ans += p2.first - p1.first;
			if(p1.second == 1)	ma.erase(p1.first);
			else	ma[p1.first]--;
			if(p2.second == 1)	ma.erase(p2.first);
			else	ma[p2.first]--;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
