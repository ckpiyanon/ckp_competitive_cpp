#include <stdio.h>
#include <string.h>

int main()
{
	char st[1000],c;
	int n,ns;
	scanf("%d",&n);
	scanf("%c",&c);
	while(n--)
	{
		ns = -1;
		while(scanf("%c",&c) != EOF)
		{
			if(c == '\n')	break;
			if(ns == -1)	st[++ns] = c;
			else if(st[ns] == '(' && c == ')')	ns--;
			else if(st[ns] == '[' && c == ']')	ns--;
			else	st[++ns] = c;
		}
		printf("%s\n",ns == -1 ? "Yes":"No");
	}

	return 0;
}
