#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int nd,n,a,b;
	while(~scanf("%d",&nd) && nd)
	{
		a = b = n = 0;
		for(int i = 0;i < 32 && nd;i++,nd >>= 1)
		{
			if(nd % 2 == 0);
			else
			{
				if(n % 2 == 0)	a |= 1 << i;
				else	b |= 1 << i;
				n++;
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}
