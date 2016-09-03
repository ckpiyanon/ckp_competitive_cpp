#include <cstdio>

int main()
{
	int n,amt = 0,in;
	char cmd[11];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",cmd);
		if(cmd[0] == 'r')	printf("%d\n",amt);
		else
		{
			scanf("%d",&in);
			amt += in;
		}
	}
	return 0;
}
