#include <bits/stdc++.h>

using namespace std;

char s1[1001],s2[1001];

int main()
{
//	freopen("in.txt","r",stdin);
	int num1[26],num2[26];
	while(gets(s1))
	{
		gets(s2);
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		for(int i = 0;s1[i];i++)	num1[s1[i] - 'a']++;
		for(int i = 0;s2[i];i++)	num2[s2[i] - 'a']++;
		for(int i = 0;i < 26;i++)
			for(int j = 0;j < min(num1[i],num2[i]);j++)
				printf("%c",i + 'a');
		printf("\n");
	}

	return 0;
}
