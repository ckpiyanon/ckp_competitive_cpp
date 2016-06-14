#include <cstdio>
#include <cstring>
int min(int a,int b)
{
	if(a > b)
		return b;
	return a;
}
int comp(char *s,int c,int lim,int len)
{
	int ans = 0;
	for(int i = len - lim - 1;i >= 0;i--)
	{
		if(c + s[i] - '0' >= 10)
			ans++,c = 1;
		else
			c = 0;
	}
	return ans;
}
int main()
{
	char inp1[15],inp2[15];
	int ans,len1,len2,lim,car;
	while(1)
	{
		scanf("%s %s",inp1,inp2);
		if(inp1[0] == '0' && inp2[0] == '0')	break;
		len1 = strlen(inp1);
		len2 = strlen(inp2);
		lim = min(len1,len2);
		ans = car = 0;
		for(int i = 0;i < lim;i++)
		{
			if(inp1[len1 - i - 1] + inp2[len2 - i - 1] - '0' - '0' + car >= 10)
				car = 1,ans++;
			else
				car = 0;
		}
		if(len1 > len2)	ans += comp(inp1,car,lim,len1);
		if(len2 > len1)	ans += comp(inp2,car,lim,len2);
		if(ans)	printf("%d ",ans);
		else	printf("No ");
		printf("carry operation");
		if(ans > 1)	printf("s.\n");
		else		printf(".\n");
	}

	return 0;
}
