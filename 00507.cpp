#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC,n,mm,idx1,idx2,sum;
	int arr[20001];
	arr[0] = 0;
	scanf("%d",&TC);
	for(int x = 1;x <= TC;x++)
	{
		scanf("%d",&n);
		for(int i = 1;i < n;i++)	scanf("%d",&arr[i]),arr[i] += arr[i-1];
		mm = idx1 = idx2 = 0;
		for(int i = 0,j = 1;j < n;j++)
		{
			if(arr[j] - arr[i] > mm || (arr[j] - arr[i] == mm && j - i > idx2 - idx1))
				mm = arr[j] - arr[i],idx2 = j,idx1 = i;
			if(arr[j] - arr[i] < 0)
				i = j;
		}
		if(mm)	printf("The nicest part of route %d is between stops %d and %d\n",x,idx1 + 1,idx2 + 1);
		else	printf("Route %d has no nice parts\n",x);
	}

	return 0;
}
