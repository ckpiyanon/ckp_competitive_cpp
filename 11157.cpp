#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	char bs,inp[20];
	int TC,nst,dist,t,cases = 1;
	scanf("%d",&TC);
	while(TC--)
	{
		v.clear();
		scanf("%d %d",&nst,&dist);
		v.push_back(0);
		v.push_back(0);
		for(int i = 0;i < nst;i++)
		{
			scanf("%s",inp);
			bs = inp[0];
			v.push_back(t = atoi(&inp[2]));
			if(bs == 'B')
				v.push_back(t);
		}
		v.push_back(dist);
		v.push_back(dist);
		t = -1000000000;
		nst = v.size();
		for(int i = 2;i < nst;i++)
			t = max(t,v[i] - v[i-2]);
		printf("Case %d: %d\n",cases++,t);
	}
}
