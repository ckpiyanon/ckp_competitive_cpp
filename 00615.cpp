#include <bits/stdc++.h>
#define SZ 100000

using namespace std;

int parent[SZ];
bool alive[SZ];

void reset() {for(int i = 0;i < SZ;i++) parent[i] = i; memset(alive,0,sizeof(alive));}
int find_set(int u)
{
	int x = u,t;
	while(x != parent[x])	x = parent[x];
	while(u != parent[u])
	{
		t = parent[u];
		parent[u] = x;
		u = t;
	}
	return x;
}
bool is_same_set(int p,int q) {return find_set(p) == find_set(q);}
void merge_set(int p,int q)
{
	int a = find_set(p),b = find_set(q);
	if(a != b)	parent[a] = b;
}

int main()
{
	bool yes = true;
	int p,q,TC = 0;
	reset();
	while(true)
	{
		scanf("%d %d",&p,&q);
		if(p == 0 && q == 0)
		{
			int prev = -1;
			for(int i = 0;i < SZ;i++)	if(alive[i])
			{
				if(prev != -1 && find_set(i) != prev)	yes = false;
				prev = find_set(i);
			}
			printf("Case %d %s a tree.\n",++TC,yes ? "is":"is not");
			reset();
			yes = true;
			continue;
		}
		if(p < 0 && q < 0)	break;
		alive[p] = alive[q] = true;
		if(is_same_set(p,q))	yes = false;
		merge_set(p,q);
	}

	return 0;
}
