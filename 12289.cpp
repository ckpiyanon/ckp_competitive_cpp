#include <bits/stdc++.h>

int main()
{
	int TC;
	char s[6],l[][6] = {"one","two","three"};
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%s",s);
		for(int i = 0;i < 3;i++)
		{
			int dif = 0;
			for(int j = 0;s[j];j++)	dif += s[j] != l[i][j];
			if(dif <= 1)
			{
				printf("%d\n",i+1);
				break;
			}
		}
	}

	return 0;
}
