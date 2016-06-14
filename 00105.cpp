#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10000];

int main()
{
	int a,b,c,mx = 0,mn = 2000000000;
	while(scanf("%d %d %d",&a,&b,&c) != EOF)
	{
		mn = min(min(a,c),mn);
		mx = max(max(a,c),mx);
		for(int i = a;i < c;i++)
			arr[i] = std::max(arr[i],b);
	}
	for(int i = mn;i < mx;i++)
		if(arr[i] != arr[i-1])
			printf("%d %d ",i,arr[i]);
	printf("%d %d\n",mx,0);

	return 0;
}
