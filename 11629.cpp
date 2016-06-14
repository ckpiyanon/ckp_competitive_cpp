#include <bits/stdc++.h>

using namespace std;

char s_[2][21];

bool chk(int a,int b,char *s)
{
	if(!strcmp(s,"="))	return a == b;
	if(!strcmp(s,"<"))	return a < b;
	if(!strcmp(s,">"))	return a > b;
	if(!strcmp(s,"<="))	return a <= b;
	if(!strcmp(s,">="))	return a >= b;
}

int main()
{
	map<string,int> point;
	int m,n,x,y;
	double xin;
	char s[201],*tok;
	scanf("%d %d",&m,&n);
	while(m--)
	{
		scanf("%s %lf",s,&xin);
		point.insert(make_pair(string(s),(int)floor(xin*100)));
	}
	for(int i = 1;i <= n;i++)
	{
		x = 0;
		while(~scanf("%s",s) && s[0] != '<' && s[0] != '>' && s[0] != '=')
			if(s[0] != '+')	x += point[string(s)];
		scanf("%d",&y); y *= 100;
		printf("Guess #%d was ",i);
		if(!chk(x,y,s))	printf("in");
		printf("correct.\n");
	}
}
