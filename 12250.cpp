#include <map>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	map<string,string> ma;
	string s;
	char inp[15];
	int TC = 1;
	ma["HELLO"] = "ENGLISH";
	ma["HOLA"] = "SPANISH";
	ma["HALLO"] = "GERMAN";
	ma["BONJOUR"] = "FRENCH";
	ma["CIAO"] = "ITALIAN";
	ma["ZDRAVSTVUJTE"] = "RUSSIAN";
	while(gets(inp))
	{
		if(inp[0] == '#')	break;
		s = ma[string(inp)];
		printf("Case %d: %s\n",TC++,s == "" ? "UNKNOWN":s.c_str());
	}

	return 0;
}
