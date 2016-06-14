#include <bits/stdc++.h>
#define INF 20000.0
#define x first
#define y second

using namespace std;

typedef pair<double,double> point;
bool operator < (point a,point b) {return a.x < b.x;}
point arr[10000];
double dist(point a,point b) {return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));}
double cal(int from,int to)
{
	if(to - from <= 1)	return INF;
	int mid = (from + to) / 2;
	double line = (arr[mid-1].x + arr[mid].x) / 2.0;
	double ans = min(cal(from,mid),cal(mid,to));
	for(int i = mid-1;i >= from && arr[i].x > line - ans;i--)
		for(int j = mid;j < to && arr[j].x < line + ans;j++)
			ans = min(ans,dist(arr[i],arr[j]));
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	double a,b;
	while(true)
	{
		scanf("%d",&n);
		if(n == 0)	break;
		for(int i = 0;i < n;i++)	scanf("%lf %lf",&arr[i].x,&arr[i].y);
		sort(arr,arr + n);
		a = cal(0,n);
		if(a < 10000.0)	printf("%.4lf\n",a);
		else	printf("INFINITY\n");
	}

	return 0;
}
