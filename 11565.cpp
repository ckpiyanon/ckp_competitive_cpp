#include <cstdio>
#define sw(a,b) (a ^= b,b ^= a,a ^= b)
#define abs(a) (a < 0 ? (-a):a)

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,a,b,c,x,y,z,t;
	bool chk;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d %d",&a,&b,&c);
		chk = true;
		for(int i = -100;i <= 100 && chk;i++)	if(i*i <= c && ((i == 0 && b == 0) || (i != 0 && b % abs(i) == 0)))
		for(int j = -100;j <= 100 && chk;j++)	if(i != j && i*i + j*j <= c)
		{
			t = a - i - j;
			if(t != i && t != j && i*j*t == b && i*i + j*j + t*t == c)
				x = i,y = j,z = t,chk = false;
		}
		if(chk)	printf("No solution.\n");
		else
		{
			if(x > y)	sw(x,y);
			if(y > z)	sw(y,z);
			if(x > y)	sw(x,y);
			printf("%d %d %d\n",x,y,z);
		}
	}

	return 0;
}
