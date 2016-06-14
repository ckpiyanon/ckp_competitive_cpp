#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	vector<pair<int,string> > all;
	unordered_map<string,int> ing;
	string title,cname;
	char cs[201];
	int TC,m,n,b,x,p;
	TC = atoi(gets(cs));
	while(TC--)
	{
		ing.clear(); all.clear();
		title = string(gets(cs));
		for(string::iterator i = title.begin();i != title.end();i++)
			*i = toupper(*i);
		scanf(" %d %d %d ",&m,&n,&b);
		while(m--)
		{
			scanf("%s %d ",cs,&x);
			ing.insert(make_pair(string(cs),x));
		}
		while(n--)
		{
			cname = string(gets(cs));
			p = 0;
			scanf(" %d ",&m);
			while(m--)
			{
				scanf(" %s %d ",cs,&x);
				p += ing[string(cs)] * x;
			}
			all.push_back(make_pair(p,cname));
		}
		sort(all.begin(),all.end());
		n = 0;
		puts(title.c_str());
		for(vector<pair<int,string> >::iterator it = all.begin();it != all.end() && it->first <= b;it++)
			puts(it->second.c_str()),n++;
		if(n == 0)	puts("Too expensive!");
		puts("");
	}

	return 0;
}
