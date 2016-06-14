#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	map<int,int> ma;
	int TC,n,x,arr[26];
	char ins[20],tar[][4] = {"QZ","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
	bool first = true,has;
	for(int i = 0;i < 10;i++) for(int j = 0;tar[i][j];j++)	arr[tar[i][j] - 'A'] = i;
	scanf("%d",&TC);
	while(TC--)
	{
		ma.clear();
		if(!first)	puts("");
		first = false;

		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",ins);
			x = 0;
			for(int i = 0;ins[i];i++)
			{
				if(isdigit(ins[i]))	x = x*10 + ins[i] - '0';
				if(isalpha(ins[i]))	x = x*10 + arr[ins[i] - 'A'];
			}
			if(ma.find(x) == ma.end())	ma.insert(make_pair(x,1));
			else	ma[x]++;
		}
		has = false;
		for(map<int,int>::iterator it = ma.begin();it != ma.end();it++)
			if(it->second > 1)
			{
				printf("%03d-%04d %d\n",it->first / 10000,it->first % 10000,it->second);
				has = true;
			}
		if(!has)	printf("No duplicates.\n");
	}

	return 0;
}
