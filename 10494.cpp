#include <bits/stdc++.h>

using namespace std;

char s[100000],ans[100000];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char ch;
	int n,len;
	long long rem;
	while(~scanf("%s",s))
	{
		scanf(" %c %d",&ch,&n);
		len = 0;
		rem = 0;
		for(int i = 0;s[i];i++)
		{
			rem = rem * 10 + s[i] - '0';
			if(!len && rem < n)	continue;
			ans[len++] = (char)(rem / n) + '0';
			rem %= n;
		}
		ans[len] = '\0';
		if(ch == '/')	puts(len > 0 ? ans:"0");
		else	printf("%lld\n",rem);
	}

	return 0;
}
