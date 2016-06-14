#include <bits/stdc++.h>

char s[1001];
int len;

bool ispalin()
{
	for(int i = 0;i < len / 2;i++)
		if(s[i] != s[len-i-1])	return false;
	return true;
}
int main()
{
//	freopen("in.txt","r",stdin);
	char c,ans[][31] = {"Uh oh..","You won\'t be eaten!"};
	while(true)
	{
		len = 0;
		while(true)
		{
			scanf("%c",&c);
			if(c == '\n')	break;
			if(!isalpha(c))	continue;
			s[len++] = toupper(c);
		}
		s[len] = '\0';
		if(!strcmp(s,"DONE"))	break;
		puts(ans[ispalin()]);
	}

	return 0;
}
