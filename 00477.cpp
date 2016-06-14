#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	char s[50],st[20];
	int np = 0,ns = 0,num;
	double sh[20][4],a,b;
	while(true)
	{
		scanf("%s",s); if(s[0] == '*') break;
		scanf("%lf %lf %lf",&sh[ns][0],&sh[ns][1],&sh[ns][2]);
		if(s[0] == 'r') scanf("%lf",&sh[ns][3]);
		st[ns] = s[0];
		ns++;
	}
	while(true)
	{
		scanf("%lf %lf",&a,&b);
		if(a == 9999.9 && b == 9999.9) break;
		np++;
		num = 0;
		for(int i = 0;i < ns;i++)
			if((st[i] == 'r' && a > sh[i][0] && a < sh[i][2] && b < sh[i][1] && b > sh[i][3]) ||
			   (st[i] == 'c' && sqrt(pow(a - sh[i][0],2) + pow(b - sh[i][1],2)) < sh[i][2]))
				printf("Point %d is contained in figure %d\n",np,i+1),num++;
		if(!num) printf("Point %d is not contained in any figure\n",np);
	}

	return 0;
}

