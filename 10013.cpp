#include <bits/stdc++.h>

using namespace std;

char ans[1000000];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC,n,a,b;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&a,&b);
			ans[i] = a + b;
		}
		for(int i = n-1;i >= 0;i--)
			if(ans[i] >= 10 && i > 0)
				ans[i] -= 10,ans[i-1]++;
		for(int i = 0;i < n;i++)	printf("%d",ans[i]);
		puts(TC ? "\n":"");
	}

	return 0;
}
