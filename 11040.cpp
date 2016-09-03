#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,arr[9][9];
	scanf("%d",&TC);
	while(TC--)
	{
		for(int i = 0;i < 9;i += 2)	for(int j = 0;j <= i;j += 2)
			scanf("%d",&arr[i][j]);
		for(int i = 0;i < 9;i++)
		{
			for(int j = 0;j <= i;j++)
			{
				if(j != 0)	printf(" ");
				int t;
				if(i % 2 == 0 && j % 2 == 0)
					t = arr[i][j];
				else if(i % 2 == 0)
					t = (arr[i-2][j-1] - arr[i][j-1] - arr[i][j+1]) / 2;
				else if(j % 2 == 0)
					t = arr[i+1][j] + ((arr[i-1][j] - arr[i+1][j] - arr[i+1][j+2]) / 2);
				else
					t = arr[i+1][j+1] + ((arr[i-1][j-1] - arr[i+1][j-1] - arr[i+1][j+1]) / 2);
				printf("%d",t);
			}
			printf("\n");
		}
	}

	return 0;
}
