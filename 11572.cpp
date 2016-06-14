#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,x,ans,pos,cnt,m,t;
	unordered_map<int,int> ma;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		ma.clear();
		ans = pos = cnt = m = 0;
		while(n--)
		{
			scanf("%d",&x);
			if(ma.find(x) != ma.end() && (t = ma[x]) >= m)
			{
				ans = max(ans,cnt);
				cnt -= t - m;
				m = t + 1;
				ma[x] = pos++;
			}
			else
			{
				ma[x] = pos++;
				cnt++;
			}
		}
		printf("%d\n",max(ans,cnt));
	}

	return 0;
}
