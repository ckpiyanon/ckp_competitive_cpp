#include <cstdio>

int main()
{
	int cases = 0;
	char in[21];
	while(gets(in) && in[0] != '*')
	{
		printf("Case %d: ",++cases);
		puts(in[0] == 'H' ? "Hajj-e-Akbar":"Hajj-e-Asghar");
	}

	return 0;
}
