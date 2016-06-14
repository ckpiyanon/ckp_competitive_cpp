#include <bits/stdc++.h>

using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w+",stdout);
	int n,m,r,c,x;
	char s[101];
	vector<string> arr;
	while(gets(s))
	{
		arr.clear();
		n = atoi(s);
		m = 0;
		for(int i = 0;i < n;i++)
		{
			arr.push_back(gets(s));
			m = max(m,(int)strlen(s));
		}
		if(m <= 58)	m += 2;
		for(int i = 0;i < 60;i++)	printf("-");
		printf("\n");
		c = 60 / m;
		if(c * m <= 60 - (m-2))	c++;
		r = (int)ceil((double)arr.size() / c);
		sort(arr.begin(),arr.end());
		for(int i = 0;i < r;i++)
		{
			for(int j = 0;j < c && j*r + i < arr.size();j++)
			{
				x = printf("%s",arr[i + j*r].c_str());
				if(i + (j+1)*r < arr.size()) for(int i = x;i < m;i++)
					printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}
