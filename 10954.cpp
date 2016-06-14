#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	priority_queue<int,vector<int>,greater<int> > pq;
	int n,a,b,ans;
	while(~scanf("%d",&n) && n)
	{
		while(!pq.empty())	pq.pop();
		while(n--)	scanf("%d",&a),pq.push(a);
		ans = 0;
		while(pq.size() >= 2)
		{
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			ans += a + b;
			pq.push(a+b);
		}
		printf("%d\n",ans);
	}

	return 0;
}
