#include <bits/stdc++.h>

using namespace std;

int _prev[100001],_next[100001];
int main()
{
//	freopen("in.txt","r",stdin);
	int s,b,l,r;
	while(~scanf("%d %d",&s,&b) && s && b)
	{
		for(int i = 0;i <= s;i++)	_prev[i] = i-1,_next[i] = i+1;
		while(b--)
		{
			scanf("%d %d",&l,&r);
			_next[_prev[l]] = _next[r];
			_prev[_next[r]] = _prev[l];
			if(_prev[l] >= 1)	printf("%d ",_prev[l]);
			else	printf("* ");
			if(_next[r] <= s)	printf("%d\n",_next[r]);
			else	printf("*\n");
		}
		printf("-\n");
	}

	return 0;
}
