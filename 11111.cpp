#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	stack<ii> st;
	string s;
	int n;
	bool chk;
	while(getline(cin,s))
	{
		istringstream is(s);
		chk = true;
		while(!st.empty()) st.pop();
		while(!is.eof() && chk)
		{
			is >> n;
			if(st.empty())
			{
				if(n < 0) st.push(ii(-n,-n));
				else chk = false;
			}
			else if(st.top().first == n) st.pop();
			else if(st.top().second > -n)
			{
				st.top().second += n;
				st.push(ii(-n,-n));
			}
			else chk = false;
		}
		if(s.length() == 0) chk = true;
		if(!st.empty()) chk = false;
		printf(chk ? ":-) Matrioshka!\n":":-( Try again.\n");
	}

	return 0;
}
