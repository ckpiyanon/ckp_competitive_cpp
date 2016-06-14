#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	unordered_map<string,int> dic;
	int m,n,p,ans;
	char s[51];
	scanf("%d %d",&m,&n);
	while(m--)
	{
		scanf("%s %d",s,&p);
		dic[s] = p;
	}
	while(n--)
	{
		ans = 0;
		while(true)
		{
			scanf("%s",s);
			ans += dic[s];
			if(s[0] == '.')	break;
		}
		printf("%d\n",ans);
	}

	return 0;
}
