#include <cstdio>
#include <vector>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int *ans[20];
	for(int i = 0;i < 20;i++)
		ans[i] = new int[1 << i];
	ans[0][0] = 1;
	for(int i = 1;i < 20;i++)
	{
		for(int j = 0;j < (1 << i);j++)
		{
			if(j < (1 << (i - 1)))
				ans[i][j] = ans[i-1][j] * 2;
			else
				ans[i][j] = ans[i][j - (1 << (i - 1))] + 1;
		}
	}

	int q,d,n;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&d,&n);
		printf("%d\n",ans[d-1][n-1]);
	}

	return 0;
}
