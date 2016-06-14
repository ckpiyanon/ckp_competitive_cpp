#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[11],s_[11];
bool palin(char *s)
{
	int len = strlen(s);
	for(int i = 0;i < len / 2;i++)
		if(s[i] != s[len - i - 1])
			return false;
	return true;
}
void rev()
{
	int len = strlen(s);
	for(int i = 0;i < len;i++)	s_[i] = s[len - i - 1];
	s_[len] = '\0';
}
unsigned int stou(char *s)
{
	int len = strlen(s);
	unsigned int ans = 0;
	for(int i = 0;i < len;i++)
		ans *= 10,ans += s[i] - '0';
	return ans;
}

int main()
{
	unsigned int n;
	int TC,len,cnt;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%u",&n);
		sprintf(s,"%u",n);
		cnt = 0;
		while(!palin(s))
		{
			cnt++;
			rev();
			n = stou(s) + stou(s_);
			sprintf(s,"%u",n);
		}
		printf("%d %s\n",cnt,s);
	}

	return 0;
}
