#include <bits/stdc++.h>
using namespace std;
double area(double x0,double y0,double x1,double y1,double x2,double y2) {return fabs((x0-x1)*(y1-y2) - (x1-x2)*(y0-y1)) / 2.0;}
bool inside(double x0,double y0,double x1,double y1,double x2,double y2,double x3,double y3)
{
	double a = area(x0,y0,x1,y1,x2,y2),b = area(x0,y0,x2,y2,x3,y3),c = area(x0,y0,x3,y3,x1,y1);
	if(a < 1e-5 || b < 1e-5 || c < 1e-5) return false;
	return fabs(a+b+c - area(x1,y1,x2,y2,x3,y3)) < 1e-5;
}
int main()
{
//	freopen("in.txt","r",stdin);
	char s[50],st[20];
	int np = 0,ns = 0,num;
	double sh[20][6],a,b;
	while(true)
	{
		scanf("%s",s); if(s[0] == '*') break;
		st[ns] = s[0];
		switch(s[0]) {
			case 'r': num = 4; break;
			case 'c': num = 3; break;
			case 't': num = 6; break;
		}
		for(int i = 0;i < num;i++) scanf("%lf",&sh[ns][i]);
		ns++;
	}
	while(true)
	{
		scanf("%lf %lf",&a,&b);
		if(a == 9999.9 && b == 9999.9) break;
		np++;
		num = 0;
//		printf("Point %d\n",np);
		for(int i = 0;i < ns;i++)
		{
			if((st[i] == 'r' && a > sh[i][0] && a < sh[i][2] && b < sh[i][1] && b > sh[i][3]) ||
			   (st[i] == 'c' && sqrt(pow(a - sh[i][0],2) + pow(b - sh[i][1],2)) < sh[i][2]) ||
			   (st[i] == 't' && inside(a,b,sh[i][0],sh[i][1],sh[i][2],sh[i][3],sh[i][4],sh[i][5])))
				printf("Point %d is contained in figure %d\n",np,i+1),num++;
		}
		if(!num) printf("Point %d is not contained in any figure\n",np);
	}

	return 0;
}

