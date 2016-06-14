#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char s[31];
	double amt = 0.0;
	bool first = true;
	map<string,int> ma;
	map<string,int>::iterator it;
	gets(s); gets(s);
	while(true)
	{
		if(gets(s) == NULL || s[0] == '\0')
		{
			if(!first)	printf("\n");
			first = false;
			for(it = ma.begin();it != ma.end();it++)
				printf("%s %.4f\n",(it->first).c_str(),100.0 * it->second / amt);
			ma.clear();
			amt = 0.0;
			if(s[0] != '\0')	break;
		}
		else
		{
			if(ma.find(s) != ma.end())	ma[s]++;
			else	ma[s] = 1;
			amt += 1;
		}
	}

	return 0;
}
