#include <bits/stdc++.h>
using namespace std;
class point {
public:
	double x,y;
	point() {}
	point(double x,double y):x(x),y(y) {}
};
class rect {
public:
	point tl,br;
	rect(double a,double b,double c,double d) {tl = point(a,b); br = point(c,d);}
	bool pointisin(point p) {return p.x > tl.x && p.y < tl.y && p.x < br.x && p.y > br.y;}
};
int main()
{
//	freopen("in.txt","r",stdin);
	char s[50];
	double a,b,c,d;
	vector<rect> r;
	while(true)
	{
		scanf("%s",s); if(s[0] == '*') break;
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		r.push_back(rect(a,b,c,d));
	}
	int x = 0;
	while(true)
	{
		scanf("%lf %lf",&a,&b);
		if(a == 9999.9 && b == 9999.9) break;
		x++;
		int num = 0;
		for(int i = 0;i < r.size();i++)
		{
			if(r[i].pointisin(point(a,b)))
				printf("Point %d is contained in figure %d\n",x,i+1),num++;
		}
		if(!num) printf("Point %d is not contained in any figure\n",x);
	}
	return 0;
}
