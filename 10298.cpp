#include <bits/stdc++.h>

using namespace std;
char s[1000005];
int p[1000005];

int cal()
{
	int m = strlen(s);
	int i = 0;
	p[0] = p[1] = 0;
	for(int j = 2;j <= m;j++)
	{
		while(i > 0 && s[i] != s[j-1])	i = p[i];
		if(s[i] == s[j-1])	i++;
		p[j] = i;
	}
	return m / (m - p[m]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(~scanf("%s",s))
	{
		if(strcmp(s,".") == 0)	break;
		printf("%d\n",cal());
	}

	return 0;
}
