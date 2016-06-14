#include <cstdio>

int calc(int a)
{
	return a >= 0 ? a:(40+a);
}
int main()
{
	int a,b,c,d;
	while(1)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(!a && !b && !c && !d)	break;
		printf("%d\n",1080 + 9*(calc(a - b) + calc(c - b) + calc(c - d)));
	}

	return 0;
}
