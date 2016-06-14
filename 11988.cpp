#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
    int n = 0;
    char s[100001];
    list<char> li;
    list<char>::iterator it;
    while(gets(s))
    {
    	li.clear();
    	it = li.begin();
    	for(int i = 0;s[i] != '\0';i++)
		{
			if(s[i] == '[')	it = li.begin();
			else if(s[i] == ']') it = li.end();
			else li.insert(it,s[i]);
		}
		for(it = li.begin();it != li.end();it++)	printf("%c",*it);
		printf("\n");
    }

    return 0;
}
