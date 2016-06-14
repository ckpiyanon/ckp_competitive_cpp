#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	stack<int> st;
	queue<int> qu;
	priority_queue<int> pq;
	int isst,isqu,ispq;
	int n,x,y,sz;
	while(~scanf("%d",&n))
	{
		while(st.size())	st.pop();
		while(qu.size())	qu.pop();
		while(pq.size())	pq.pop();
		isst = isqu = ispq = true;
		sz = 0;
		while(n--)
		{
			scanf("%d %d",&x,&y);
			if(x == 1)	st.push(y),qu.push(y),pq.push(y),sz++;
			else
			{
				if(sz == 0)
				{
					isst = isqu = ispq = false;
					continue;
				}
				if(st.top() != y)	isst = false;
				if(qu.front() != y)	isqu = false;
				if(pq.top() != y)	ispq = false;
				st.pop(),qu.pop(),pq.pop();
				sz--;
			}
		}
		if(isst + isqu + ispq == 1)
		{
			if(isst)
				printf("stack\n");
			else if(isqu)
				printf("queue\n");
			else
				printf("priority queue\n");
		}
		else if(isst + isqu + ispq == 0)
			printf("impossible\n");
		else	printf("not sure\n");
	}

	return 0;
}
