#include <bits/stdc++.h>

using namespace std;

int calc(int num)
{
	int ans = 0;
	for(int i = 1;i < num;i++)	if(num % i == 0)
	{
		ans += i;
	}
	if(ans == num)	return 0;
	if(ans < num)	return 1;
	return 2;
}

int main()
{
//	freopen("in.txt","r",stdin);
	char ans[][10] = {"PERFECT","DEFICIENT","ABUNDANT"};
	int num;
	puts("PERFECTION OUTPUT");
	while(~scanf("%d",&num) && num)
	{
		printf("%5d  %s\n",num,ans[calc(num)]);
	}
	puts("END OF OUTPUT");

	return 0;
}
