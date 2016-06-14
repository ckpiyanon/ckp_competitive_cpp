#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int vg[100000],vb[100000];
int mmin(int a,int b,int c)
{
	int x = a;
	if(x > b)	x = b;
	if(x > c)	x = c;
	return x;
}
int main()
{
//	freopen("in.txt","r",stdin);
	priority_queue<int> qg,qb;
	int TC,b,sg,sb,t;
	scanf("%d",&TC);
	while(TC--)
	{
		while(!qg.empty())	qg.pop();
		while(!qb.empty())	qb.pop();
		scanf("%d %d %d",&b,&sg,&sb);
		for(int i = 0;i < sg;i++)	scanf("%d",&t),qg.push(t);
		for(int i = 0;i < sb;i++)	scanf("%d",&t),qb.push(t);
		while(!qg.empty() && !qb.empty())
		{
			t = mmin(b,qg.size(),qb.size());
			for(int i = 0;i < t;i++)
				vg[i] = qg.top(),vb[i] = qb.top(),qg.pop(),qb.pop();
			for(int i = 0;i < t;i++)
			{
				if(vg[i] > vb[i])		qg.push(vg[i] - vb[i]);
				else if(vg[i] < vb[i])	qb.push(vb[i] - vg[i]);
			}
		}
		if(qg.empty() && qb.empty())	printf("green and blue died\n");
		else if(qb.empty())
		{
			printf("green wins\n");
			while(!qg.empty())
			{
				printf("%d\n",qg.top());
				qg.pop();
			}
		}
		else if(qg.empty())
		{
			printf("blue wins\n");
			while(!qb.empty())
			{
				printf("%d\n",qb.top());
				qb.pop();
			}
		}
		if(TC)	printf("\n");
	}

	return 0;
}
