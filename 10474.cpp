#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	vector<int> arr;
	int n,q,t,TC = 0,ma[10001];
	while(~scanf("%d %d",&n,&q) && n && q)
	{
		memset(ma,0,sizeof(ma));
		arr.clear();
		while(n--)
		{
			scanf("%d",&t);
			arr.push_back(t);
		}
		sort(arr.begin(),arr.end());
		for(int i = 0;i < arr.size();i++)
			if(!ma[arr[i]])	ma[arr[i]] = i+1;
		printf("CASE# %d:\n",++TC);
		while(q--)
		{
			scanf("%d",&t);
			if(ma[t]) printf("%d found at %d\n",t,ma[t]);
			else printf("%d not found\n",t);
		}
	}
	return 0;
}
