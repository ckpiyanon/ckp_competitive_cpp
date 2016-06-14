#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int TC,n,arr[1000],t,t_;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)	scanf("%d",arr + i);
		sort(arr,arr + n);
		if(n % 2)	t = arr[0] + (n == 1 ? 0:(arr[1] + arr[2]));
		else		t = arr[1];
		t_ = arr[0] + arr[1] + arr[1];
		for(int i = n - 1;i > 2;i -= 2)	t += arr[i] + t_;
		printf("%d\n",t);
		t = n - 1;
		while(t > 2)
		{
			if(arr[t] - arr[t-1] > 1)
			{
				printf("%d %d\n",arr[0],arr[1]);
				printf("%d\n",arr[0]);
				printf("%d %d\n",arr[t-1],arr[t]);
				if(t == 1)	break;
				printf("%d\n",arr[1]);
				t -= 2;
			}
			else
			{

			}
		}
		if(t == 2)	printf("%d %d\n%d\n%d %d\n",arr[0],arr[1],arr[0],arr[0],arr[2]);
		else if(t)	printf("%d %d\n",arr[0],arr[1]);
		else		printf("%d\n",arr[0]);
		if(TC)		printf("\n");
	}

	return 0;
}
