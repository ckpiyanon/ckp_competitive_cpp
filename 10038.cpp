#include <cstdio>
#include <cstring>

int mabs(int a)
{
	return a < 0 ? (-a):(a);
}
int main()
{
	int n,x,y;
	bool chk[3000],ans;
	char s[2][11] = {"Not jolly\n","Jolly\n"};
	while(scanf("%d",&n) != EOF)
	{
		memset(chk,0,3000);
		scanf("%d",&x);
		for(int i = 1;i < n;i++)
		{
			scanf("%d",&y);
			chk[mabs(y-x) - 1] = true;
			x = y;
		}
		ans = true;
		for(int i = 0;i < n-1;i++)
		{
			if(!chk[i])
			{
				ans = false;
				break;
			}
		}
		printf(s[ans]);
	}

	return 0;
}
