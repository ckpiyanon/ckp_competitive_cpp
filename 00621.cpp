#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int len,TC;
	getline(cin,s);
	TC = atoi(s.c_str());
	while(TC--)
	{
		getline(cin,s);
		len = s.length();
		if(s == "1" || s == "4" || s == "78")	puts("+");
		else if(s[len - 2] == '3' && s[len - 1] == '5')	puts("-");
		else if(s[0] == '9' && s[len - 1] == '4')		puts("*");
		else if(s[0] == '1' && s[1] == '9' && s[2] == '0')	puts("?");
	}

	return 0;
}
