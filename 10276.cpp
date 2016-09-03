#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n,arr[50],sq,i,j;
	bool nomoremove;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		nomoremove = false;
		memset(arr,0,sizeof(arr));
		for(i = 1;!nomoremove;i++)
		{
			for(j = 0;j < n && !nomoremove;j++)
			{
				sq = (int)sqrt(arr[j] + i);
				if(arr[j] == 0 || sq * sq == arr[j] + i)
				{
					arr[j] = i;
					break;
				}
			}
			if(j >= n)	break;
		}
		printf("%d\n",i - 1);
	}

	return 0;
}
