#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	vector<pair<int,int> > li;
	int m,n,u,v,TC,x,arr[30],mtrx[8][30];
	bool yes;
	scanf("%d",&TC);
	while(TC--)
	{
		memset(arr,0,sizeof(arr));
		scanf("%d %d",&m,&n);
		li.clear();
		yes = true;
		for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
			scanf("%d",&mtrx[i][j]),arr[j] += mtrx[i][j];
		for(int i = 0;i < n;i++) if(arr[i] != 2)
			yes = false;
		if(yes)
		{
			for(int i = 0;i < n;i++)
			{
				u = v = -1;
				for(int j = 0;j < m && (u == -1 || v == -1);j++)
					if(mtrx[j][i])
					{
						if(u == -1)	u = j;
						else		v = j;
					}
				li.push_back(make_pair(u,v));
			}
			sort(li.begin(),li.end());
			for(int i = 1;i < li.size();i++) if(li[i] == li[i-1])
				yes = false;
		}
		puts(yes ? "Yes":"No");
	}

	return 0;
}
