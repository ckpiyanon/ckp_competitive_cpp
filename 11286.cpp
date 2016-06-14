#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	map<string,int> ma;
	string s;
	char cs[1001];
	int n,arr[5],x,ans;
	while(1)
	{
		scanf("%d",&n);
		if(!n)	break;
		x = 0;
		ma.clear();
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < 5;j++)	scanf("%d",arr + j);
			sort(arr,arr + 5);
			sprintf(cs,"%d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4]);
			s = string(cs);
			if(ma.find(s) != ma.end())	ma[s]++;
			else	ma.insert(make_pair(s,1));
			x = max(ma[s],x);
		}
		ans = 0;
		for(map<string,int>::iterator i = ma.begin();i != ma.end();i++)
			if(i->second == x)	ans += i->second;
		printf("%d\n",ans);
	}

	return 0;
}
