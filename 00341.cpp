#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,w,v,TC = 0;
	while(~scanf("%d",&n) && n)
	{
		graph.assign(10,vii());
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d %d",&v,&w);
				v--;
				graph[i].push_back(ii(w,v));
			}
		}
	}

	return 0;
}
