#include <cstdio>
#include <cstring>

int n;
int g[15][15],v[15];
int prev(int n)
{
	int i = 0;
	while(!g[i][n] && i < 15)	i++;
	return i;
}
int next(int x)
{
	int i = 0;
	while(!g[x][i] && i < n)	i++;
	return i;
}
bool cycle(int k)
{
	int x = next(k);
	while(x != k && x != n)	x = next(x);
	if(x == k)	return true;
	return false;
}
int src(int n)
{
	int x = prev(n);
	while(x != 15)	n = x,x = prev(n);
	return n;
}
void clrc(int x)
{
	while(!v[x])
	{
		v[x] = true;
		x = next(x);
	}
}
void clr(int x)
{
	v[x] = true;
	for(int i = 0;i < n;i++)
		if(g[x][i])	clr(i);
}
int main()
{
	freopen("in.txt","r",stdin);
	int a,b,cy,ch;
	scanf("%d",&n);
	while(n)
	{
		memset(g,0,sizeof(g));
		memset(v,0,sizeof(v));
		while(true)
		{
			scanf("%d %d",&a,&b);
			if(a == -1 && b == -1)	break;
			g[a-1][b-1] = true;
		}
		a = cy = ch = 0;
		for(int i = 0;i < n;i++)
		{
			if(!v[i])
			{
				ch++;
				if(cycle(i))	cy++,clrc(i);
				else			clr(src(i));
			}
		}
		if(cy == ch)	ch--;
		printf("** %d %d\n",cy,ch);
		printf("%d\n",cy + ch - 1);
		scanf("%d",&n);
	}

	return 0;
}
