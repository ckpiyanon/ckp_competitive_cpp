#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	bitset<3651> bs;
	int TC,n,p,x;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&n,&p);
		bs.reset();
		while(p--)
		{
			scanf("%d",&x);
			for(int i = x;i <= n;i += x)	bs.set(i,true);
		}
		x = 0;
		for(int i = 1;i <= n;i++)	if(bs[i] && (i - 1) % 7 < 5)	x++;
		printf("%d\n",x);
	}

	return 0;
}
