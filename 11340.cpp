#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,arr[256],n,len;
	char s[10010];
	double sum;
	TC = atoi(gets(s));
	while(TC--)
	{
		memset(arr,0,sizeof(arr));
		n = atoi(gets(s));
		while(n--)
		{
			gets(s);
			arr[s[0]] = atoi(&s[2]);
		}
		n = atoi(gets(s));
		sum = 0;
		while(n--)
		{
			len = strlen(gets(s));
			for(int i = 0;i < len;i++)
				sum += arr[s[i]];
		}
		printf("%0.2lf$\n",sum / 100.0);
	}

	return 0;
}
