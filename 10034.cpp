#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;
typedef pair<double,ii> iii;
typedef vector<iii> viii;

viii edges;
int n;

class disjoint_set
{
public:
	int *ds,*rk,num;
	disjoint_set(int n)
	{
		ds = new int[n];
		rk = new int[n];
		num = n;
		memset(rk,0,n*sizeof(int));
		for(int i = 0;i < n;i++)	ds[i] = i;
	}
	~disjoint_set(){delete[]ds,delete[]rk;}
	int find(int n)
	{
		int root = n,tmp;
		while(root != ds[root])	root = ds[root];
		while(n != root)
		{
			tmp = ds[n];
			ds[n] = root;
			n = tmp;
		}
		return root;
	}
	void join(int a,int b)
	{
		int x = find(a),y = find(b);
		if(x == y)	return;
		if(rk[x] > rk[y])	ds[x] = y;
		else
		{
			ds[y] = x;
			if(rk[x] == rk[y])	rk[x]++,rk[y]++;
		}
		num--;
	}
};
double dist(double x1,double y1,double x2,double y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

double kruskal()
{
	disjoint_set ds(n);
	iii e;
	double ans = 0.0;
	for(int i = 0;i < edges.size() && ds.num > 1;i++)
	{
		e = edges[i];
		if(ds.find(e.Y.X) == ds.find(e.Y.Y))	continue;
		ds.join(e.Y.X,e.Y.Y);
		ans += e.X;
	}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	double x[100],y[100];
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&n);
		edges.clear();
		for(int i = 0;i < n;i++)	scanf("%lf %lf",x + i,y + i);
		for(int i = 0;i < n;i++) for(int j = i+1;j < n;j++)
			edges.push_back(iii(dist(x[i],y[i],x[j],y[j]),ii(i,j)));
		sort(edges.begin(),edges.end());
		printf("%.2lf\n",kruskal());
		if(TC)	printf("\n");
	}

	return 0;
}
