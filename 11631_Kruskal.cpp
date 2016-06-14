#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

class edge
{
public:
	int u,v,w;
	edge(int u,int v,int w)
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
	static int cmp(edge a,edge b) {return a.w < b.w;}
};
int ds[200000];
int ds_find(int u)
{
	int tmp,root = u;
	while(root != ds[root])	root = ds[root];
	while(u != ds[u])
	{
		tmp = ds[u];
		ds[u] = root;
		u = ds[u];
	}
	return root;
}
void ds_merge(int a,int b)
{
	int x = ds_find(a),y = ds_find(b);
	if(x == y)	return;
	ds[x] = y;
}
bool ds_same(int a,int b) {return ds_find(a) == ds_find(b);}

int main()
{
//	freopen("in.txt","r",stdin);
	vector<edge> edge_list;
	int m,n,x,y,z,total;
	while(true)
	{
		scanf("%d %d",&m,&n);
		if(m == 0 && n == 0)	break;
		edge_list.clear();
		total = 0;
		while(n--)
		{
			scanf("%d %d %d",&x,&y,&z);
			total += z;
			edge_list.push_back(edge(x,y,z));
		}
		sort(edge_list.begin(),edge_list.end(),edge::cmp);
		n = 0;
		for(int i = 0;i < m;i++)	ds[i] = i;
		for(vector<edge>::iterator i = edge_list.begin();i != edge_list.end();i++) if(!ds_same(i->u,i->v))
			ds_merge(i->u,i->v),n += i->w;
		printf("%d\n",total - n);
	}

	return 0;
}
