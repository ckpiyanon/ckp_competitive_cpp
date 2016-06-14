#include <bits/stdc++.h>

using namespace std;

class arr{
public:
	int base,d,esz,c[11];
	arr() {}
	arr(int base,int esz,int d,int *lo,int *up):base(base),esz(esz),d(d)
	{
		c[d] = esz;
		for(int i = d-1;i > 0;i--)	c[i] = c[i+1]*(up[i] - lo[i] + 1);
		c[0] = base;
		for(int i = 1;i <= d;i++)	c[0] -= c[i]*lo[i-1];
	}
	int addr(int *I)
	{
		int ans = c[0];
		for(int i = 0;i < d;i++)	ans += c[i+1]*I[i];
		return ans;
	}
};

int main()
{
//	freopen("in.txt","r",stdin);
	map<string,arr> ma;
	arr elem;
	int n,q,base,esz,d,lo[10],up[10],in[10];
	char name[11];
	bool first;
	scanf("%d %d",&n,&q);
	while(n--)
	{
		scanf("%s %d %d %d",name,&base,&esz,&d);
		for(int i = 0;i < d;i++)	scanf("%d %d",lo + i,up + i);
		ma.insert(make_pair(string(name),arr(base,esz,d,lo,up)));
	}
	while(q--)
	{
		scanf("%s",name);
		elem = ma[string(name)];
		for(int i = 0;i < elem.d;i++)	scanf("%d",in + i);
		printf("%s[",name);
		first = true;
		for(int i = 0;i < elem.d;i++)
		{
			if(!first)	printf(", ");
			first = false;
			printf("%d",in[i]);
		}
		printf("] = %d\n",elem.addr(in));
	}

	return 0;
}
