#include <bits/stdc++.h>

using namespace std;

char arr[100][300],rule[300];
int n,m;

void play(int idx)
{
	if(!rule[idx])
	{
		printf("\n");
		return;
	}
	if(rule[idx] == '#') for(int i = 0;i < n;i++)
	{
		printf(arr[i]);
		play(idx + 1);
	}
	else for(int i = 0;i < 10;i++)
	{
		printf("%d",i);
		play(idx + 1);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		for(int i = 0;i < n;i++)	scanf("%s",arr[i]);
		scanf("%d",&m);
		printf("--\n");
		while(m--)
		{
			scanf("%s",rule);
			play(0);
		}
	}

	return 0;
}
