#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,k;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&n,&k);
		printf("%d\n",(k ^ (k >> 1)) % (1 << n));
	}

	return 0;
}
