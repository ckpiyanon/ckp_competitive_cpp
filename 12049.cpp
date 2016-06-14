#include <bits/stdc++.h>

using namespace std;

int arr1[10000],arr2[10000];

int main()
{
	int TC,m,n,rm;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&m,&n);
		for(int i = 0;i < m;i++)	scanf("%d",arr1 + i);
		for(int i = 0;i < n;i++)	scanf("%d",arr2 + i);
		sort(arr1,arr1 + m); sort(arr2,arr2 + n);
		int i = 0,j = 0;
		rm = 0;
		while(i < m && j < n)
		{
			if(arr1[i] == arr2[j])
				i++,j++;
			else if(arr1[i] < arr2[j])
				i++,rm++;
			else if(arr1[i] > arr2[j])
				j++,rm++;
		}
		printf("%d\n",rm + m + n - i - j);
	}

	return 0;
}
