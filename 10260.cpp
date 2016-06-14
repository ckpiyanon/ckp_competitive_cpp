#include <bits/stdc++.h>

int main()
{
//	freopen("in.txt","r",stdin);
	int prev,val[26];
	char s[21],v[][10] = {"AEIOUHWY","BFPV","CGJKQSXZ","DT","L","MN","R"};
	for(int i = 0;i < 7;i++)	for(int j = 0;v[i][j];j++)
		val[v[i][j] - 'A'] = i;
	while(gets(s))
	{
		prev = 0;
		for(int i = 0;s[i];i++)
		{
			s[i] -= 'A';
			if(val[s[i]] == prev)	continue;
			if(val[s[i]])	printf("%d",val[s[i]]);
			prev = val[s[i]];
		}
		printf("\n");
	}

	return 0;
}
