#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,d,r,sum;
	int m[100],a[100];
	while(~scanf("%d %d %d",&n,&d,&r) && n && d && r)
	{
		for(int i = 0;i < n;i++)	scanf("%d",&m[i]);
		for(int i = 0;i < n;i++)	scanf("%d",&a[i]);
		sort(m,m + n);	sort(a,a + n);
		for(int i = 0;i < n/2;i++)	swap(a[i],a[n-i-1]);
		sum = 0;
		for(int i = 0;i < n;i++)	sum += max(0,m[i] + a[i] - d);
		printf("%d\n",sum * r);
	}

	return 0;
}
