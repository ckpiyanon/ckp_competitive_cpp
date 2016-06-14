#include <bits/stdc++.h>

using namespace std;

int ft[200010],N,tmp;
void update(int idx,int num)
{
	while(idx <= N)
	{
		ft[idx] += num;
		idx += idx & (-idx);
	}
}
int qry(int idx)
{
	int num = 0;
	while(idx > 0)
	{
		num += ft[idx];
		idx -= idx & (-idx);
	}
	return num;
}
int qry(int from,int to)
{
	return qry(to) - qry(from - 1);
}
int main()
{
//	freopen("in.txt","r",stdin);
	char s[10];
	int a,b,TC = 0;
	while(true)
	{
		scanf("%d",&N);
		if(N == 0)	break;
		if(TC > 0)	printf("\n");
		printf("Case %d:\n",++TC);
		memset(ft,0,sizeof(ft));
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			update(i + 1,tmp);
		}
		while(true)
		{
			scanf("%s",s);
			if(strcmp(s,"END") == 0)	break;
			scanf("%d %d",&a,&b);
			if(toupper(s[0]) == 'S')	update(a,b - qry(a,a));
			else			printf("%d\n",qry(a,b));
		}
	}

	return 0;
}
