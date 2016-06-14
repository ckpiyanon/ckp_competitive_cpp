#include <bits/stdc++.h>
using namespace std;
int main()
{
	int TC,n,m;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&n,&m);
		for(int i = 0;i < m;i++)
		{
			for(int j = 0;j < n;j++)
			{
				for(int k = 0;k <= j;k++)
					printf("%d",j+1);
				printf("\n");
			}
			for(int j = n-1;j > 0;j--)
			{
				for(int k = 0;k < j;k++)
					printf("%d",j);
				printf("\n");
			}
			if(i < m-1 || TC) printf("\n");
		}
	}

	return 0;
}
