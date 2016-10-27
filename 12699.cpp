#include <bits/stdc++.h>

double pa[1000001],pd[1000001];
int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,d,s,a;
	pa[0] = pd[0] = 0; pa[1] = pd[1] = 1; pa[2] = 1; pd[2] = 2;
	for(int i = 3;i < 1000000;i += 2)
	{
		pa[i+1] = pa[(i+1) / 2];
		pa[i] = 0.5 * (1 + pa[i+1] + pa[i-1]);
		pd[i+1] = 1 + pd[(i+1) / 2];
		pd[i] = 0.5 * (pd[i+1] + pd[i-1]);
	}
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d %d %d",&n,&d,&s,&a);
		printf("%.3f\n",d*pd[n] + s*pa[n] + a*pa[n]);
	}

	return 0;
}
