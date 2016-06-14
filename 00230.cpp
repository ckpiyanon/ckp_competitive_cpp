#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int x,y,z;
	string s,s1,s2;
	vector<pair<string,string> > arr;
	vector<int> cmd;
	while(getline(cin,s))
	{
		if(s == "END")	break;
		for(x = 1;s[x] != '"';x++);
		s1 = s.substr(1,x - 1);
		s2 = s.substr(x + 5,s.length());
		arr.push_back(make_pair(s2,s1));
	}
	sort(arr.begin(),arr.end());
	while(getline(cin,s))
	{
		if(s == "END")	break;
		if(s == "SHELVE")
		{
			sort(cmd.begin(),cmd.end());
			for(vector<int>::iterator it = cmd.begin();it != cmd.end();it++)
			{
				if(*it == 0)	cout << "Put \"" << arr[*it].second << " first" << endl;
				else	cout << "Put \"" << arr[*it].second << " after \"" << arr[*it - 1].second << endl;
			}
			cmd.clear();
			cout << "END" << endl;
			continue;
		}
		s1 = s.substr(0,x = s.find_first_of(" "));
		if(s1 == "RETURN")
		{
			s2 = s.substr(x + 2,s.length() - 1);
			for(y = 0;arr[y].second != s2;y++);
			cmd.push_back(y);
		}
	}

	return 0;
}
