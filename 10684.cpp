#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int n,mm,sum,x;
	while(scanf("%d",&n) != EOF && n)
	{
		mm = sum = 0;
		while(n--)
		{
			scanf("%d",&x);
			if(sum + x < 0)	sum = 0;
			else	sum += x;
			mm = max(mm,sum);
		}
		if(mm)	printf("The maximum winning streak is %d.\n",mm);
		else	printf("Losing streak.\n");
	}

	return 0;
}
