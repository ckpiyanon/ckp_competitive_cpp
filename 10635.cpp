#include <bits/stdc++.h>
using namespace std;
int last[70000],ma[62501],arr[62500];
int main()
{
	freopen("in.txt","r",stdin);
	int TC,n,p,q,t,t1;
	scanf("%d",&TC);
	for(int x = 1;x <= TC;x++)
	{
		scanf("%d %d %d",&n,&p,&q);
		memset(ma,0,sizeof(ma));
		for(int i = 0;i <= p;i++)	scanf("%d",&t),ma[t] = i+1;
		t1 = p+1;
		for(int i = 0;i <= q;i++)	scanf("%d",&t),arr[i] = ma[t] ? ma[t]:(t1++);
		memset(last,0,sizeof(last));
		t = 1;
		for(int i = 0;i <= q;i++)
			for(int j = t;j > 0;j--)
				if(last[j] < arr[i] && (last[j+1] > arr[i] || last[j+1] == 0))
				{
					t = max(t,j+1);
					last[j+1] = arr[i];
				}
		printf("Case %d: %d\n",x,t);
		for(int i = 1;i <= t;i++)	printf("%d\n",last[i]);
	}

	return 0;
}
