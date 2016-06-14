#include <bits/stdc++.h>
#define INF 2000000
using namespace std;
class point {
public:
	int x,y;
	point(int x,int y):x(x),y(y) {}
};
bool operator < (point a,point b) {if(a.x == b.x) return a.y < b.y; return a.x < b.x;}
int maxdist(point a,point b) {return max(abs(a.x - b.x),abs(a.y - b.y));}
vector<point> arr;
int calc(int from,int to)
{
	if(to - from <= 1) return INF;
	if(to - from == 2) return maxdist(arr[from],arr[from+1]);
	int mid = (from + to) / 2;
	int line = (arr[mid-1].x + arr[mid].x) / 2;
	int ans = min(calc(from,mid),calc(mid,to));
	for(int i = mid;i < to && arr[i].x <= line + ans;i++)
		for(int j = mid - 1;j >= 0 && arr[j].x >= line - ans;j--)
			ans = min(ans,maxdist(arr[i],arr[j]));
	return ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,x,y;
	while(scanf("%d",&n) != EOF)
	{
		arr.clear();
		while(n--) scanf("%d %d",&x,&y),arr.push_back(point(x,y));
		sort(arr.begin(),arr.end());
		printf("%d\n",calc(0,arr.size()));
	}

	return 0;
}
