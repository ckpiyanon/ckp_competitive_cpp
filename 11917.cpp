#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	map<string,int> ma;
	map<string,int>::iterator it;
	int TC,n,x;
	char s[21];
	scanf("%d",&TC);
	for(int tc = 1;tc <= TC;tc++)
	{
		ma.clear();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s %d",s,&x);
			ma[s] = x;
		}
		scanf("%d %s",&x,s);
		it = ma.find(s);
		printf("Case %d: ",tc);
		if(it == ma.end() || it->second > x + 5)
			printf("Do your own homework!");
		else if(it->second <= x)
			printf("Yesss");
		else
			printf("Late");
		printf("\n");
	}

	return 0;
}
