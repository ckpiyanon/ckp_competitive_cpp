#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,n;
	string s;
	vector<int> idx;
	vector<string> arr;
	getline(cin,s);
	TC = atoi(s.c_str());
	while(TC--)
	{
		idx.clear(); arr.clear();
		getline(cin,s); getline(cin,s);
		istringstream is(s);
		while(!is.eof())
		{
			is >> n;
			idx.push_back(n - 1);
		}
		arr = vector<string>(idx.size());
		for(int i = 0;i < idx.size();i++)
		{
			cin >> s;
			arr[idx[i]] = s;
		}
		for(vector<string>::iterator it = arr.begin();it != arr.end();it++)
			cout << *it << endl;
		cin.ignore();
		if(TC)	puts("");
	}

	return 0;
}
