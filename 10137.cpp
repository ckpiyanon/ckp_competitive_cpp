#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	double arr[1000],avg,ans1,ans2;
	while(~scanf("%d",&n) && n)
	{
		avg = 0;
		for(int i = 0;i < n;i++)	scanf("%lf",&arr[i]),avg += arr[i];
		avg /= n;
		avg = round(avg * 100) / 100.0;
		ans1 = ans2 = 0;
		for(int i = 0;i < n;i++)
		{
			if(arr[i] > avg)	ans1 += arr[i] - avg;
			else	ans2 += avg - arr[i];
		}
		printf("$%.2f\n",min(ans1,ans2));
	}

	return 0;
}
