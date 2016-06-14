#include <bits/stdc++.h>

using namespace std;

int arr[2000000];

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	bool first;
	while(true)
	{
		scanf("%d",&n);
		if(!n)	break;
		for(int i = 0;i < n;i++)	scanf("%d",&arr[i]);
		sort(arr,arr+n);
		first = true;
		for(int i = 0;i < n;i++)
		{
			if(!first)	printf(" ");
			first = false;
			printf("%d",arr[i]);
		}
		printf("\n");
	}

	return 0;
}
