#include <bits/stdc++.h>

using namespace std;

class info {
public:
	static const int TYPE_ENTER = 0;
	static const int TYPE_EXIT = 1;
	int hr,gate,type;
	string date;
	info(string date,int gate,int type):gate(gate),type(type)
	{
		this->date = date;
		this->hr = (date[6] - '0')*10 + date[7] - '0';
	}
};
bool operator <(const info& a,const info& o) {return a.date < o.date;}

int main()
{
	int TC,fare[24];
	char s[101],*tok;
	vector<pair<string,info> > arr;
	vector<pair<string,int> > ans;
	TC = atoi(gets(s));
	gets(s);
	while(TC--)
	{
		arr.clear(); ans.clear();
		gets(s);
		tok = strtok(s," ");
		for(int i = 0;i < 24;i++,tok = strtok(NULL," "))
			fare[i] = atoi(tok);
		while(gets(s) && strlen(s))
		{
			string plate,date,ts;
			int type,gate;
			tok = strtok(s," ");
			plate = string(tok);
			tok = strtok(NULL," ");
			date = string(tok);
			tok = strtok(NULL," ");
			type = strcmp(tok,"exit") == 0;
			tok = strtok(NULL," ");
			gate = atoi(tok);
			arr.push_back(make_pair(plate,info(date,gate,type)));
		}
		sort(arr.begin(),arr.end());
		int bill = 0,trip = 0;
		for(int i = 1;i < arr.size();i++)
		{
			pair<string,info> cp = arr[i],pp = arr[i-1];
			info ci = cp.second,pi = pp.second;
			if(cp.first == pp.first && ci.type == info::TYPE_EXIT && pi.type == info::TYPE_ENTER)
			{
				bill += abs(ci.gate - pi.gate) * fare[pi.hr];
				trip++;
			}
			if((cp.first != pp.first || i == arr.size() - 1) && trip != 0)
			{
				ans.push_back(make_pair(pp.first,bill + 200 + trip * 100));
				bill = 0;
				trip = 0;
			}
		}
		for(vector<pair<string,int> >::iterator it = ans.begin();it != ans.end();it++)
			printf("%s $%.2f\n",(it->first).c_str(),it->second / 100.0);
		if(TC)	printf("\n");
	}

	return 0;
}
