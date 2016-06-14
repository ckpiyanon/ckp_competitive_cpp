#include <cstdio>

int main()
{
	int n,x,bal,cnt = 0;
	while(1)
	{
		scanf("%d",&n);
		if(!n)	break;
		bal = 0;
		while(n--)
		{
			scanf("%d",&x);
			bal += x > 0 ? 1:-1;
		}
		printf("Case %d: %d\n",++cnt,bal);
	}

	return 0;
}
