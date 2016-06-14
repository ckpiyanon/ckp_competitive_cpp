#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	vector<int> arr;
	int n,x;
	bool ok;
	while(~scanf("%d",&n) && n)
	{
		arr.clear();
		while(n--)
		{
			scanf("%d",&x);
			arr.push_back(x);
		}
		sort(arr.begin(),arr.end());
		ok = true;
		for(int i = 1;i < arr.size() && ok;i++)	if(arr[i] - arr[i-1] > 200)
			ok = false;
		ok &= (1422 - arr[arr.size() - 1]) * 2 <= 200;
		puts(ok ? "POSSIBLE":"IMPOSSIBLE");
	}

	return 0;
}
