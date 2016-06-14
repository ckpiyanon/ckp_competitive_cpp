#include <bits/stdc++.h>

using namespace std;

char pre[30],in[30];

void post(int pre_0,int pre_1,int in_0,int in_1)
{
	char ch = pre[pre_0];
	int pos = -1;
	for(int i = in_0;i <= in_1;i++) if(in[i] == ch) {pos = i; break;}
	int x = pre_0 + pos - in_0;
	if(pre_0 + 1 <= x)	post(pre_0 + 1,x,in_0,pos - 1);
	if(x + 1 <= pre_1)	post(x + 1,pre_1,pos + 1,in_1);
	printf("%c",ch);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int l;
	while(~scanf("%s %s",pre,in))
		post(0,l = strlen(pre) - 1,0,l),printf("\n");
	return 0;
}
