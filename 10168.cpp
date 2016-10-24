#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
vector<bool> is_prime;
void init()
{
	int n = (int)ceil(sqrt(10000000));
	is_prime = vector<bool>(n+1);
	is_prime.assign(is_prime.size(),true);
	for(int i = 2;i <= n;i = i == 2 ? 3:(i + 2))
	{
		if(!is_prime[i])	continue;
		prime.push_back(i);
		for(int j = i+i;j <= n;j += i)
			is_prime[j] = false;
	}
}
bool check_prime(int n)
{
	for(int i = 0;i < prime.size() && prime[i]*prime[i] <= n;i++)
		if(n % prime[i] == 0)	return false;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	init();
	int n;
	while(~scanf("%d",&n))
	{
		if(n < 8)	puts("Impossible.");
		else
		{
			if(n & 1)	{printf("2 3 "); n -= 5;}
			else	{printf("2 2 "); n -= 4;}
			for(int i = 0;i < prime.size();i++)
				if(check_prime(n - prime[i]))
				{
					printf("%d %d\n",prime[i],n - prime[i]);
					break;
				}
		}
	}

	return 0;
}
