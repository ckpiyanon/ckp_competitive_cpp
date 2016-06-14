#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

class disjoint_set {
public:
	int *ds,*rk,n;
	disjoint_set(int n)
	{
		this->n = n;
		ds = new int[n];
		rk = new int[n];
		clear();
	}
	~disjoint_set()
	{
		delete[] ds;
		delete[] rk;
	}
	void clear()
	{
		for(int i = 0;i < n;i++)	ds[i] = i;
		memset(rk,0,sizeof(int)*n);
	}
	int rt(int n)
	{
		int root = n,tmp;
		while(root != ds[root])	root = ds[root];
		while(n != root)	tmp = ds[n],ds[n] = root,n = tmp;
		return root;
	}
	void join(int a,int b)
	{
		int x = rt(a),y = rt(b);
		if(x == y)	return;
		if(rk[x] > rk[y])	ds[y] = x;
		else
		{
			ds[x] = y;
			if(rk[x] == rk[y])	rk[y]++;
		}
		n--;
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	int TC,N,M,A,t1,t2,t3,numa,ans;
	vector<iii> edge_list;
	for(int TC_ = 1;TC_ <= TC;TC_++)
	{
		scanf("%d %d %d",&N,&M,&A);
		disjoint_set ds(N);
		edge_list.clear();
		for(int i = 0;i < M;i++)
		{
			scanf("%d %d %d",&t1,&t2,&t3);
			edge_list.push_back(iii(t3,ii(t1,t2)));
		}
		sort(edge_list.begin(),edge_list.end());
		ans = 0;
		for(int i = 0;i < edge_list.size();i++)
		{
			iii p = edge_list[i];
			if(ds.rt(p.second.first) != ds.rt(p.second.second))
			{
				ans += p.first;
				ds.join(p.second.first,p.second.second);
			}
		}
		numa = ds.n;
		printf("Case #%d: %d %d\n",TC_,ans + (A * numa),numa);
	}

	return 0;
}
