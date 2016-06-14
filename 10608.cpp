#include <bits/stdc++.h>
using namespace std;
class union_find
{
public:
	vector<int> p,sz;
	union_find(int n)
	{
		p = vector<int>(n);
		sz = vector<int>(n);
		for(int i = 0;i < n;i++) p[i] = i;
		sz.assign(n,1);
	}
	int find(int n)
	{
		int pr = n,t;
		while(p[pr] != pr)	pr = p[pr];
		while(n != pr)
		{
			t = p[n];
			p[n] = pr;
			n = t;
		}
		return pr;
	}
	void merge(int a,int b)
	{
		int x = find(a),y = find(b);
		if(x == y)	return;
		p[x] = y;
		sz[y] += sz[x];
	}
	int size(int n) {return sz[find(n)];}
};
int main()
{
	int TC,n,m,a,b;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d",&n,&m);
		union_find uf(n);
		while(m--)
		{
			scanf("%d %d",&a,&b);
			uf.merge(a-1,b-1);
		}
		a = 0;
		for(int i = 0;i < n;i++) a = max(a,uf.size(i));
		printf("%d\n",a);
	}
	return 0;
}
