#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	vector<string> arr;
	string s;
	int len = 0;
	while(!cin.eof())
	{
		getline(cin,s);
		if(s.length() == 0) break;
		len = max((int)s.length(),len);
		arr.push_back(s);
	}
	for(int j = 0;j < len;j++)
	{
		for(int i = arr.size() - 1;i >= 0;i--)
		{
			if(j < arr[i].length()) printf("%c",arr[i][j]);
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}
