#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	unordered_map<string,string> dic;
	char s1[11],s[31];
	while(strlen(gets(s)) != 0)
	{
		strcpy(s1,strtok(s," "));
		dic[strtok(NULL," ")] = s1;
	}
	while(gets(s))	puts(dic.find(s) == dic.end() ? "eh":dic[s].c_str());

	return 0;
}
