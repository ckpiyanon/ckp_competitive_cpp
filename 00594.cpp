#include <bits/stdc++.h>

int main()
{
	int n;
	char *b = (char*)&n;
	while(~scanf("%d",&n))
	{
		printf("%d converts to ",n);
		std::swap(b[0],b[3]);
		std::swap(b[1],b[2]);
		printf("%d\n",n);
	}

	return 0;
}
