#include <bits/stdc++.h>

using namespace std;

char s[2001];

int main()
{
//	freopen("in.txt","r",stdin);
	int q;
	long long n,x;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld %s",&n,s);
		x = 0;
		for(int i = 0;s[i];i++)
		{
			x = x * 10 + s[i] - '0';
			x %= n;
		}
		printf("%lld\n",x);
	}

	return 0;
}
