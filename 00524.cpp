#include <bits/stdc++.h>
#define IS_PRIME(N) binary_search(prime,prime + 12,N)

using namespace std;

bool visited[17];
int n,arr[16];
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37};
void print()
{
	for(int i = 0;i < n;i++)
	{
		if(i)	printf(" ");
		printf("%d",arr[i]);
	}
	printf("\n");
}
void dfs(int idx,int num)
{
	if(idx == n - 1)
	{
		if(IS_PRIME(num + 1))	print();
		return;
	}
	for(int i = 2;i <= n;i++) if(!visited[i] && IS_PRIME(num + i))
	{
		visited[i] = true;
		arr[idx + 1] = i;
		dfs(idx + 1,i);
		visited[i] = false;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int TC = 0;
	while(~scanf("%d",&n))
	{
		if(TC)	printf("\n");
		printf("Case %d:\n",++TC);
		arr[0] = 1;
		visited[1] = true;
		dfs(0,1);
	}

	return 0;
}
