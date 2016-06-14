#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC;
	char s[2][201],delim[] = "{},:",*tok,ans[] = "+-*";
	map<string,string> ma[2];
	vector<string> li[3];
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%s %s",s[0],s[1]);
		ma[0].clear(); ma[1].clear();
		for(int i = 0;i < 3;i++)	li[i].clear();
		for(int i = 0;i < 2;i++)
		{
			tok = strtok(s[i],delim);
			while(tok)
			{
				ma[i].insert(make_pair(string(tok),string(strtok(NULL,delim))));
				tok = strtok(NULL,delim);
			}
		}
		for(map<string,string>::iterator it = ma[0].begin();it != ma[0].end();it++)
			if(ma[1].find(it->first) == ma[1].end())
				li[1].push_back(it->first);
		for(vector<string>::iterator it = li[1].begin();it != li[1].end();it++)
			ma[0].erase(*it);
		for(map<string,string>::iterator it = ma[1].begin();it != ma[1].end();it++)
			if(ma[0].find(it->first) == ma[0].end())
				li[0].push_back(it->first);
		for(vector<string>::iterator it = li[0].begin();it != li[0].end();it++)
			ma[1].erase(*it);
		map<string,string>::iterator it[2];
		it[0] = ma[0].begin();	it[1] = ma[1].begin();
		while(it[0] != ma[0].end() && it[1] != ma[1].end())
		{
			if(it[0]->second != it[1]->second)
				li[2].push_back(it[0]->first);
			it[0]++; it[1]++;
		}
		if(!li[0].size() && !li[1].size() && !li[2].size())
			printf("No changes\n");
		else for(int i = 0;i < 3;i++)
		{
			sort(li[i].begin(),li[i].end());
			if(!li[i].size())	continue;
			printf("%c",ans[i]);
			bool first = true;
			for(vector<string>::iterator it = li[i].begin();it != li[i].end();it++)
			{
				if(!first)	printf(",");
				first = false;
				printf("%s",it->c_str());
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
