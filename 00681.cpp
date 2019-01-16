#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
const double PI = 22.0 / 7;
const double HPI = PI / 2;
int direction(ii a,ii b,ii c)
{
	return (b.X - a.X)*(c.Y - a.Y) - (b.Y - a.Y)*(c.X - a.X);
}
bool is_equal(double a,double b)
{
	return fabs(a - b) < 1E-6;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
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
		if(arr[arr.size() - 1] == arr[0])
            arr.pop_back();
		scanf("%d",&x);
		idx = 0;
		for(int i = 1;i < arr.size();i++)
			if(arr[i].Y < arr[idx].Y || arr[i].Y == arr[idx].Y && arr[i].X < arr[idx].X)
				idx = i;
		swap(arr[0],arr[idx]);
		ii tp = arr[0];
		sort(arr.begin() + 1,arr.end(),[&tp](const ii &a,const ii &b) -> bool {
			double angle_a = atan2(a.Y - tp.Y,a.X - tp.X);
			double angle_b = atan2(b.Y - tp.Y,b.X - tp.X);
			if(is_equal(angle_a,angle_b))
                return pow(a.Y - tp.Y,2) + pow(a.X - tp.X,2) > pow(b.Y - tp.Y,2) + pow(b.X - tp.X,2);
			return angle_a < angle_b;
		});
		convex.clear();
		arr.push_back(arr[0]);
		convex.push_back(arr[0]);
		convex.push_back(arr[1]);
		for(int i = 2;i < arr.size();i++)
		{
			ii p = arr[i];
			ii p_ = arr[i - 1];
			if(is_equal(atan2(p.Y - tp.Y,p.X - tp.X),atan2(p_.Y - tp.Y,p_.X - tp.X)))
				continue;
			while(convex.size() >= 2 && direction(convex[convex.size() - 2],convex[convex.size() - 1],p) <= 0)
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
