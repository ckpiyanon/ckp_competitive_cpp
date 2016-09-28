#include <bits/stdc++.h>
#define ADD(from,f,to,t) (graph[from*2 + f][to*2 + t] = true)

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC,m,n,ns,na,s1,s2,a1,a2,disS,disA;
	bool yes,dirS,dirA,graph[120][120];
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d %d %d",&ns,&na,&m);
		memset(graph,0,sizeof(graph));
		n = (ns + na) * 2;
		while(m--)
		{
			scanf("%d %d %d %d",&s1,&a1,&s2,&a2);
			s1--; a1 += ns - 1; s2--; a2 += ns - 1;
			disS = s1 - s2; disA = a1 - a2;
			if(!disS && !disA)	continue;
			dirS = disA > 0;	dirA = disS > 0;
			if(!disS)
				ADD(s1,dirS^1,s1,dirS);
			else if(!disA)
				ADD(a1,dirA^1,a1,dirA);
			else
			{
				ADD(s1,dirS^1,s2,dirS);	ADD(s1,dirS^1,a1,dirA);
				ADD(a2,dirA^1,s2,dirS);	ADD(a2,dirA^1,a1,dirA);
				ADD(s2,dirS^1,s1,dirS);	ADD(s2,dirS^1,a2,dirA);
				ADD(a1,dirA^1,s1,dirS);	ADD(a1,dirA^1,a2,dirA);
			}
		}
		for(int k = 0;k < n;k++)
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n;j++)
					graph[i][j] |= graph[i][k] && graph[k][j];
		yes = true;
		for(int i = 0;i < n && yes;i += 2)
			if(graph[i][i^1] && graph[i^1][i])
				yes = false;
		puts(yes ? "Yes":"No");
	}

	return 0;
}
