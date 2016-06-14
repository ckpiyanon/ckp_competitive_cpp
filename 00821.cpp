#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	bitset<100> ex(0);
	int x,y,arr[100][100],cnt,cases = 0;
	double sum;
	scanf("%d %d",&x,&y);
	while(x && y)
	{
		ex.reset();
		memset(arr,1,sizeof(arr));
		ex[x-1] = ex[y-1] = 1;
		arr[x-1][y-1] = 1;
		scanf("%d %d",&x,&y);
		while(x && y)
		{
			ex[x-1] = ex[y-1] = 1;
			arr[x-1][y-1] = 1;
			scanf("%d %d",&x,&y);
		}
		for(int h = 0;h < 100;h++)
		{
			if(!ex[h])	continue;
			for(int i = 0;i < 100;i++)
			{
				if(!ex[h])	continue;
				for(int j = 0;j < 100;j++)
				{
					if(!ex[h])	continue;
					arr[i][j] = min(arr[i][j],arr[i][h] + arr[h][j]);
				}
			}
		}
		sum = cnt = 0;
		for(int i = 0;i < 100;i++)
		{
			if(!ex[i])	continue;
			for(int j = 0;j < 100;j++)
			{
				if(!ex[j] || arr[i][j] > 1000000 || i == j)	continue;
				sum += arr[i][j];
				cnt++;
			}
		}
		printf("Case %d: average length between pages = %.3lf clicks\n",++cases,sum / cnt);
		scanf("%d %d",&x,&y);
	}

	return 0;
}
