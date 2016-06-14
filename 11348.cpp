#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,m,x,num,mx;
	vector<set<int> > arr(10001);
	int own[50];
	scanf("%d",&TC);
	for(int tc = 1;tc <= TC;tc++)
	{
		scanf("%d",&n);
		arr.assign(10001,set<int>());
		mx = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&x);
				arr[x].insert(i);
				mx = max(mx,x);
			}
		}
		num = 0; memset(own,0,sizeof(own));
		for(int i = 0;i <= mx;i++) if(arr[i].size() == 1)
			own[*arr[i].begin()]++,num++;
		printf("Case %d:",tc);
		for(int i = 0;i < n;i++)
			printf(" %f%%",100.0 * own[i] / num);
		printf("\n");
	}

	return 0;
}
