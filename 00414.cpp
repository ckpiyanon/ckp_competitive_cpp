#include <bits/stdc++.h>

using namespace std;

int num_of(char *s,char ch)
{
	int num = 0;
	for(int i = 0;s[i];i++)
		if(s[i] == ch)	num++;
	return num;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,ans;
	char s[26];
	int arr[20];
	while(true)
	{
		n = atoi(gets(s));
		if(n == 0)	break;
		m = INT_MAX;
		for(int i = 0;i < n;i++)
			m = min(m,arr[i] = num_of(gets(s),' '));
		ans = 0;
		for(int i = 0;i < n;i++)
			ans += arr[i] - m;
		printf("%d\n",ans);
	}

	return 0;
}
