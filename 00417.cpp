#include <map>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

map<string,int> ma;

void per(int x,int n,string str)
{
	if(n == 0)
	{
		ma.insert(make_pair(str,ma.size() + 1));
		return;
	}
	for(int i = x;i < 26;i++)	per(i+1,n-1,str + (char)('a' + i));
}

int main()
{
	char s[6];
	for(int i = 1;i <= 5;i++)	per(0,i,"");
	while(gets(s))	printf("%d\n",ma[string(s)]);

	return 0;
}
