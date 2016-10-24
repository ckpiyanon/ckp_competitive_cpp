#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> point;
typedef pair<point,point> line;

line l; int x[4],y[4]; vector<line> lines;

bool on_segment(point p,point q,point r) {return q.X <= max(p.X,r.X) && q.X >= min(p.X,r.X) && q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y);}
int orientation(point p,point q,point r)
{
	int val = (q.Y - p.Y)*(r.X - q.X) - (q.X - p.X)*(r.Y - q.Y);
	return val == 0 ? 0:(val < 0 ? 1:2);
}
bool intersect(line l0)
{
	int o1 = orientation(l.first,l.second,l0.first);
	int o2 = orientation(l.first,l.second,l0.second);
	int o3 = orientation(l0.first,l0.second,l.first);
	int o4 = orientation(l0.first,l0.second,l.second);
	return	o1 && o2 && o3 && o4 && o1 != o2 && o3 != o4 ||
		o1 == 0 && on_segment(l.first,l0.first,l.second) ||
		o2 == 0 && on_segment(l.first,l0.second,l.second) ||
		o3 == 0 && on_segment(l0.first,l.first,l0.second) ||
		o4 == 0 && on_segment(l0.first,l.second,l0.second);
}
bool intersect()
{
	if(x[0] >= x[2] && x[1] >= x[2] && x[0] <= x[3] && x[1] <= x[3] && y[0] >= y[2] && y[1] >= y[2] && y[0] <= y[3] && y[1] <= y[3])
		return true;
	for(int i = 0;i < lines.size();i++) if(intersect(lines[i]))
		return true;
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		for(int i = 0;i < 4;i++)	scanf("%d %d",x + i,y + i);
		l = line(point(x[0],y[0]),point(x[1],y[1]));
		lines.clear();
		if(x[2] > x[3])	swap(x[2],x[3]);
		if(y[2] > y[3])	swap(y[2],y[3]);
		lines.push_back(line(point(x[2],y[2]),point(x[3],y[2])));
		lines.push_back(line(point(x[3],y[2]),point(x[3],y[3])));
		lines.push_back(line(point(x[3],y[3]),point(x[2],y[3])));
		lines.push_back(line(point(x[2],y[3]),point(x[2],y[2])));
		puts(intersect() ? "T":"F");
	}

	return 0;
}
