#include <bits/stdc++.h>

int main()
{
//	freopen("in.txt","r",stdin);
	int n,t,arr[110];
	bool first;
	while(true)
	{
		scanf("%d",&n);
		if(!n)	break;
		memset(arr,0,sizeof(arr));
		while(n--)
		{
			scanf("%d",&t);
			arr[t]++;
		}
		first = true;
		for(int i = 0;i < 100;i++)
		{
			while(arr[i]--)
			{
				if(!first)	printf(" ");
				first = false;
				printf("%d",i);
			}
		}
		printf("\n");
	}

	return 0;
}
