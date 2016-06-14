#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC,m,n,x,l;
	vector<int> arr,seq;
	set<ii> s;
	set<ii>::iterator sit;
	scanf("%d",&TC);
	while(TC--)
	{
		arr.clear(); seq.clear(); s.clear(); l = 0;
		scanf("%d %d",&m,&n);
		while(m--)	scanf("%d",&x),arr.push_back(x);
		while(n--)	scanf("%d",&x),seq.push_back(x);
		sort(seq.begin(),seq.end());
		for(int i = 0,j = 0;i < arr.size();i++)
		{
			s.insert(ii(arr[i],i));
			if(s.size() == 1)	sit = s.find(ii(arr[i],i));
			if(arr[i] < sit->first)	sit--;
			while(l)
			{
				sit++;
				if(sit == s.end())
				{
					sit--;
					break;
				}
				l--;
			}
			while(j < seq.size() && i+1 == seq[j])
			{
				printf("%d\n",sit->first);
				j++;
				sit++;
				if(sit == s.end())
				{
					sit--;
					l++;
				}
			}
		}
		if(TC)	printf("\n");
	}

	return 0;
}
