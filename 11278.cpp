#include <bits/stdc++.h>

char s[1001];

int main()
{
//	freopen("in.txt","r",stdin);
	char s1[] = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?";
	char s2[] = "`123qjlmfp/[]~!@#QJLMFP?{}456.orsuyb;=\\$%^>ORSUYB:+|789aehtdck-&*(AEHTDCK_0zx,inwvg')ZX<INWVG\"";
	char arr[256];
	int len;
	for(int i = 0;i < 256;i++)	arr[i] = (char)i;
	for(int i = 0;s1[i] != '\0';i++)
		arr[s1[i]] = s2[i];
	while(gets(s))
	{
		len = strlen(s);
		for(int i = 0;i < len;i++)
			printf("%c",arr[s[i]]);
		printf("\n");
	}

	return 0;
}
