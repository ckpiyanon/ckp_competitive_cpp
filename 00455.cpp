#include <cstdio>
#include <cstring>

int len,TC,t,ans;
char s[81];

bool check(int per)
{
	for(int i = 0;i < len;i += per)
		if(strncmp(s,s + i,per))
			return false;
	return true;
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%s",s);
		len = strlen(s);
		ans = 0;
		for(int i = 1;i <= len && !ans;i++)
			if(len % i == 0 && check(i))
				ans = i;
		printf("%d\n",ans);
		if(TC)	printf("\n");
	}

	return 0;
}
