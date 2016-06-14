#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	list<int> li;
	int p,c,x,e,TC = 0;
	char s[10];
	while(~scanf("%d %d",&p,&c) && p && c)
	{
		li.clear();
		printf("Case %d:\n",++TC);
		for(int i = 1;i <= min(p,1000);i++)	li.push_back(i);
		while(c--)
		{
			scanf("%s",s);
			if(s[0] == 'E')
			{
				scanf("%d",&e);
				li.remove(e);
				li.push_front(e);
			}
			else
			{
				printf("%d\n",li.front());
				li.push_back(li.front());
				li.pop_front();
			}
		}
	}
	return 0;
}
