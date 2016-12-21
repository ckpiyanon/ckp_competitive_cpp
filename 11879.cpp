#include <bits/stdc++.h>

using namespace std;

char s[110];

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	while(gets(s))
	{
		if(s[0] == '0' && s[1] == '\0')	break;
		n = 0;
		for(int i = 0;s[i];i++)	n = (n * 10 + s[i] - '0') % 17;
		printf("%d\n",!n);
	}

	return 0;
}
