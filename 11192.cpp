#include <bits/stdc++.h>

using namespace std;

void rev(char *p1,char *p2)
{
	p2--;
	while(p1 < p2)	swap(*p1,*p2),p1++,p2--;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int x,len;
	char s[101];
	while(~scanf("%d",&x) && x)
	{
		scanf("%s",s);
		x = (len = strlen(s)) / x;
		for(int i = 0;i < len;i += x)
			rev(s + i,min(s + i + x,s + len));
		puts(s);
	}

	return 0;
}
