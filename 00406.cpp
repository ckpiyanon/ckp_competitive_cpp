#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int N,C,from,to,mid,t;
	bitset<1000> is_not_prime;
	vector<int> prime;
	prime.push_back(1);
	for(int i = 2;i < 1000;i++) if(!is_not_prime[i])
	{
		for(int j = i+i;j < 1000;j += i)	is_not_prime[j] = true;
		prime.push_back(i);
	}
	while(scanf("%d %d",&N,&C) != EOF)
	{
		printf("%d %d:",N,C);
		from = 0; to = prime.size(); mid = to / 2;
		while(prime[mid] != N && from < to - 1)
		{
			if(N > prime[mid])	from = mid;
			else	to = mid;
			mid = (from + to) / 2;
		}
		t = mid + 1;
		mid = (mid + 1) / 2;
		from = max(mid - C + (t % 2),0);
		to = min(mid + C,t);
		for(int i = from;i < to;i++)	printf(" %d",prime[i]);
		printf("\n\n");
	}

	return 0;
}
