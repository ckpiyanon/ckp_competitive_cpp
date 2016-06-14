#include <bits/stdc++.h>

using namespace std;

int main()
{
	char cmd[10];
	int numt,x,n;
	map<int,int> team;
	map<int,queue<int> > qmap;
	queue<int> q;
	while(~scanf("%d",&numt) && numt)
	{
		q.clear();
		qmap.clear();
		team.clear();
		for(int i = 0;i < numt;i++)
		{
			scanf("%d",&n);
			qmap[i] = queue<int>();
			while(n--)
			{
				scanf("%d",&x);
				team[x] = i;
			}
		}
		while(true)
		{
			scanf("%s",cmd);
			if(strcmp(cmd,"STOP") == 0)	break;
		}
		puts("");
	}

	return 0;
}
