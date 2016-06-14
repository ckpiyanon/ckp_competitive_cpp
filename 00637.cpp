#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j;
	while(~scanf("%d",&n) && n)
	{
		m = n % 4 ? (n + (4 - (n%4))):n;
		i = 1,j = m;
		printf("Printing order for %d pages:\n",n);
		while(i < j)
		{
			printf("Sheet %d, front: ",i/2 + 1);
			if(j > n) printf("Blank");
			else printf("%d",j);
			printf(", %d\n",i);
			if(i >= n) break;
			printf("Sheet %d, back : ",i/2 + 1);
			printf("%d, ",i+1);
			if(j-1 > n) printf("Blank\n");
			else printf("%d\n",j-1);
			i += 2;
			j -= 2;
		}
	}
	return 0;
}
