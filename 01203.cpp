#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int main()
{
//	freopen("in.txt","r",stdin);
	priority_queue<iii,vector<iii>,greater<iii> > pq;
	char s[9];
	int x,y,n;
	while(~scanf("%s",s) && strcmp(s,"Register") == 0)
	{
		scanf("%d %d",&x,&y);
		pq.push(iii(ii(y,x),y));
	}
	scanf("%d",&n);
	while(n--)
	{
		iii p = pq.top();	pq.pop();
		printf("%d\n",p.first.second);
		p.first.first += p.second;
		pq.push(p);
	}

	return 0;
}
