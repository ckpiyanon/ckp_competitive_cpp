#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
int direction(ii a,ii b,ii c)
{return (b.X - a.X)*(c.Y - a.Y) - (b.Y - a.Y)*(c.X - a.X);}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC,n,x,y,idx;
	bool last_dir;
	vector<ii> arr,convex;
	scanf("%d",&TC);
	printf("%d\n",TC);
	while(TC--)
	{
		scanf("%d",&n);
		arr.clear();
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&x,&y);
			arr.push_back(ii(x,y));
		}
		arr.pop_back();
		scanf("%d",&x);
		idx = 0;
		for(int i = 1;i < arr.size();i++)
			if(arr[i].Y < arr[idx].Y || arr[i].Y == arr[idx].Y && arr[i].X < arr[idx].X)
				idx = i;
		convex.clear();
		for(int i = 0;i <= arr.size();i++)
		{
			ii p = arr[(idx + i) % arr.size()];
			while(convex.size() >= 2 && direction(convex[convex.size() - 2],convex[convex.size() - 1],p) < 0)
				convex.pop_back();
			convex.push_back(p);
		}
		printf("%d\n",convex.size());
		for(int i = 0;i < convex.size();i++)
			printf("%d %d\n",convex[i].X,convex[i].Y);
		if(TC)	printf("-1\n");
	}

	return 0;
}