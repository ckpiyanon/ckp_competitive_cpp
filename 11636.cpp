#include <cstdio>
#include <cmath>

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	for(int i = 1;;i++)
	{
		scanf("%d",&n);
		if(n < 0)	break;
		printf("Case %d: %d\n",i,(int)ceil(log(n)/log(2)));
	}

	return 0;
}
