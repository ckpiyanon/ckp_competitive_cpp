#include <bits/stdc++.h>
using namespace std;
class point
{
public:
	int x,y;
	point(int x,int y):x(x),y(y) {}
};
double dist(point a,point b) {return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));}
double graph[101][101];
int main()
{
//	freopen("in.txt","r",stdin);
	vector<point> arr;
	int TC,n,x,y,im;
	double mm;
	scanf("%d",&TC);
	for(int X = 1;X <= TC;X++)
	{
		arr.clear();
		printf("Case #%d:\n",X);
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&x,&y);
			arr.push_back(point(x,y));
		}
		for(int i = 0;i < 101;i++) for(int j = 0;j < 101;j++) graph[i][j] = i == j ? 0:1000000;
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
		{
			if(i == j)	graph[i][j] = graph[j][i] = 0;
			else if(dist(arr[i],arr[j]) <= 10.0)
				graph[i][j] = graph[j][i] = dist(arr[i],arr[j]);
		}
		for(int k = 0;k < n;k++) for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
			graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
		im = false;
		mm = 0;
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
		{
			im |= !(graph[i][j] < 10000.0);
			mm = max(mm,graph[i][j]);
		}
		if(im) printf("Send Kurdy\n");
		else printf("%.4f\n",mm);
		printf("\n");
	}

	return 0;
}
