#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> seq;

struct cmp {
public:
	bool operator()(const int &a,const int &b) const{return seq[a] < seq[b];}
};

map<int,int,cmp> num;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i = 0;
	while(~scanf("%d",&n))
	{
		if(seq.find(n) == seq.end())	seq[n] = i++;
		if(num[n] == 0)	num[n] = 1;
		else	num[n]++;
	}
	for(map<int,int,cmp>::iterator it = num.begin();it != num.end();it++)
		printf("%d %d\n",it->first,it->second);

	return 0;
}
