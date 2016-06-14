#include <bits/stdc++.h>

using namespace std;

char s1[60],s2[60];

int find_idx(char ch,char *s,int b,int e)
{
	for(;b <= e;b++)	if(s[b] == ch)	return b;
	return -1;
}

void run(int bp,int ep,int bi,int ei)
{
	int p = find_idx(s1[bp],s2,bi,ei);
	int numl = p - bi;
	if(p > bi)	run(bp+1,bp+numl,bi,p-1);
	if(p < ei)	run(bp+numl+1,ep,p+1,ei);
	printf("%c",s1[bp]);
}

int main()
{
	int TC,len;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %s %s",&len,s1,s2);
		run(0,len-1,0,len-1);
		printf("\n");
	}

    return 0;
}
