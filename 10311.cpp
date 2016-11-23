#include <bits/stdc++.h>
#define MAX 100000001

using namespace std;

int prime[6000000],N = 0; bitset<MAX> is_prime;

int main()
{
//	freopen("in.txt","r",stdin);
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	for(int i = 4;i < MAX;i += 2)	is_prime[i] = false;
	for(int i = 3;i*i < MAX;i += 2) if(is_prime[i])
		for(int j = i*i;j < MAX;j += i + i)	is_prime[j] = false;
	prime[N++] = 2;
	for(int i = 3;i < MAX;i += 2) if(is_prime[i])	prime[N++] = i;
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int ans = 0;
		if(n & 1)
			ans = n > 3 && is_prime[n - 2] ? 2:0;
		else
		{
			int x = lower_bound(prime,prime + N,n >> 1) - prime;
			while(prime[x] >= (n >> 1))	x--;
			for(;x >= 0;x--) if(is_prime[n - prime[x]])
			{
				ans = prime[x]; break;
			}
		}
		if(ans)	printf("%d is the sum of %d and %d.\n",n,ans,n - ans);
		else	printf("%d is not the sum of two primes!\n",n);
	}

	return 0;
}
