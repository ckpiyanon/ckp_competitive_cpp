#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	map<string,string> ma;
	int n;
	string s1,s2;
	cin >> n;
	cin.ignore();
	while(n--)
	{
		getline(cin,s1); getline(cin,s2);
		ma.insert(make_pair(s1,s2));
	}
	cin >> n;
	cin.ignore();
	while(n--)
	{
		getline(cin,s1);
		cout << ma[s1] << endl;
	}

	return 0;
}
