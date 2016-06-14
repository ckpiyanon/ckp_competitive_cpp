#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int s,l[12],TC = 0,x;
	bool ok;
	while(~scanf("%d",&s) && s >= 0)
	{
		for(int i = 0;i < 12;i++)	scanf("%d",l + i);
		printf("Case %d:\n",++TC);
		for(int i = 0;i < 12;i++)
		{
			scanf("%d",&x);
			ok = true;
			if(s < x)	ok = false;
			else	s -= x;
			s += l[i];
			printf("No problem%s\n",ok ? "! :D":". :(");
		}
	}

	return 0;
}
