#include <bits/stdc++.h>
using namespace std;

int total,len,arr[30],n;
int bitans;
void play(int bits,int idx,int sum)
{
	if(sum > len) return;
	if(sum > total) total = sum,bitans = bits;
	if(idx >= n) return;
	play(bits | (1 << idx),idx + 1,sum + arr[idx]);
	play(bits,idx + 1,sum);
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(~scanf("%d %d",&len,&n))
	{
		for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
		total = 0;
		play(0,0,0);
		for(int i = 0;i < n;i++) if((bitans >> i) % 2) printf("%d ",arr[i]);
		printf("sum:%d\n",total);
	}

	return 0;
}
