#include <bits/stdc++.h>

int main()
{
	char c;
	while(scanf("%c",&c) != EOF)
	{
		if(c == '\n')
		{
			printf("\n");
			continue;
		}
		printf("%c",(char)(c - 7));
	}

	return 0;
}
