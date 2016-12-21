#include <bits/stdc++.h>

using namespace std;

char ans[1000000];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC,n;
	char a,b;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf(" %c %c",&a,&b);
			ans[i] = a - '0' + b - '0';
		}
		for(int i = n-1;i >= 0;i--)
			if(ans[i] >= 10 && i > 0)
				ans[i] -= 10,ans[i-1]++;
		if(ans[0] >= 10)	putchar('1'),ans[0] -= 10;
		for(int i = 0;i < n;i++)	putchar(ans[i] + '0');
		puts(TC ? "\n":"");
	}

	return 0;
}
