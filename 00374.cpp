#include <bits/stdc++.h>

using namespace std;

int modpow(int b,int p,int m)
{
	if(p == 0)	return 1;
	if(p == 1)	return b % m;
	int x = p / 2;
	int ans1 = modpow(b,x,m) % m;
	return (((ans1 * ans1) % m) * (modpow(b,p - x*2,m) % m)) % m;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int b,p,m;
	while(~scanf("%d %d %d",&b,&p,&m))
		printf("%d\n",modpow(b % m,p,m));

	return 0;
}
