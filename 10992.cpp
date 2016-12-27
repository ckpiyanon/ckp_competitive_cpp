#include <bits/stdc++.h>

using namespace std;

char s[51];

int rem(char *s,int n)
{
	int x = 0;
	for(int i = 0;s[i];i++)
		x = (x * 10 + s[i] - '0') % n;
	return x;
}

int main()
{
//	freopen("in.txt","r",stdin);
	char names[][51] = {"Tanveer Ahsan","Shahriar Manzoor","Adrian Kugel","Anton Maydell",
		"Derek Kisman","Rezaul Alam Chowdhury","Jimmy Mardell","Monirul Hasan","K. M. Iftekhar"};
	int d[] = {2,5,7,11,15,20,28,36};
	int len,TC = 0;
	bool has;
	while(gets(s) && s[0] != '0')
	{
		len = strlen(s);
		has = false;
		if(TC++)	puts("");
		puts(s);
		if(!(len < 4 || len == 4 && atoi(s) < 2148))
		{
			for(int i = 0;i < 8;i++)
			{
				if(rem(s,d[i]) == 2148 % d[i])
					printf("Ghost of %s!!!\n",names[i]),has = true;
			}
			int r4 = rem(s,4),r100 = rem(s,100),r400 = rem(s,400);
			if(r4 == 0 && r100 != 0 || r400 == 0)	printf("Ghost of %s!!!\n",names[8]),has = true;
		}
		if(!has)	puts("No ghost will come in this year");
	}

	return 0;
}
