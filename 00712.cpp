#include <bits/stdc++.h>
using namespace std;

int btoi(char *s)
{
	int ans = 0;
	for(int i = 0;s[i];i++)
		ans = (ans << 1) + (s[i] - '0');
	return ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
	char ins[101],str[101];
    int n,m,TC = 0;
    while(scanf("%d",&n) != EOF && n)
    {
    	printf("S-Tree #%d:\n",++TC);
    	for(int i = 0;i < n;i++)	scanf("%s",ins);
		scanf("%s %d",str,&m);
		while(m--)
		{
			scanf("%s",ins);
			printf("%c",str[btoi(ins)]);
		}
		printf("\n\n");
    }

    return 0;
}
