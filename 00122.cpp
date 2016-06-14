#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
	bool operator()(const string a,const string b)
	{
		if(a.length() == b.length())	return a < b;
		return a.length() < b.length();
	}
};
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	long long x;
	char cs[1001],*tok;
	map<string,long long,cmp> tree;
	bool yes = true;
	while(~scanf("%s",cs))
	{
		if(strcmp(cs,"()"))
		{
			tok = strtok(cs,"(),");
			x = atoll(tok);
			tok = strtok(NULL,"(),");
			string key(tok ? tok:"");
			if(tree.find(key) != tree.end())	yes = false;
			tree[key] = x;
		}
		else
		{
			for(map<string,long long>::iterator it = tree.begin();it != tree.end();it++)
			{
				string s = it->first;
				if(s.length() > 0 && tree.find(s.substr(0,s.length() - 1)) == tree.end())
					yes = false;
			}
			if(!yes)	printf("not complete");
			else
			{
				for(map<string,long long>::iterator it = tree.begin();it != tree.end();it++)
				{
					if(!yes)	printf(" ");
					yes = false;
					printf("%lld",it->second);
				}
			}
			printf("\n");
			tree.clear();
			yes = true;
		}
	}

	return 0;
}
