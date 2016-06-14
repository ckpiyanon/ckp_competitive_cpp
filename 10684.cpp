#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int n,mm,sum;
	int arr[10001];
	arr[0] = 0;
	while(scanf("%d",&n) != EOF && n)
	{
		for(int i = 0;i < n;i++)	scanf("%d",&arr[i]);
		mm = sum = 0;
		for(int i = 0;i < n;i++)
		{
			sum += arr[i];
			mm = max(mm,sum);
			if(sum < 0)	sum = 0;
		}
		if(mm)	printf("The maximum winning streak is %d.\n",mm);
		else	printf("Losing streak.\n");
	}

	return 0;
}
