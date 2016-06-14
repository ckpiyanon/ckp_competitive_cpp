#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int val[10010],lnode[10010],rnode[10010];
int ii[10010],ip[10010];
char str[100001];
int N,nNode,ans;

int find_index(int *arr,int start,int stop,int val)
{
	for(int i = start;i <= stop;i++)	if(arr[i] == val)	return i;
	return -1;
}
int construct_tree(int bp,int ep,int bi,int ei)
{
	int idx = nNode++;
	val[idx] = ip[ep];
	int p = find_index(ii,bi,ei,val[idx]);
	int numr = ei - p;
	lnode[idx] = p > bi ? construct_tree(bp,ep-numr-1,bi,p-1):-1;
	rnode[idx] = p < ei ? construct_tree(ep-numr,ep-1,p+1,ei):-1;
	return idx;
}
/// first-> sum, second->ans
pii calc(int idx)
{
	int il = lnode[idx],ir = rnode[idx];
	int v = val[idx];
	pii p;
	if(il == -1 && ir == -1)	return make_pair(v,v);
	if(il == -1)
	{
		p = calc(ir);
		return make_pair(p.first + v,p.second);
	}
	if(ir == -1)
	{
		p = calc(il);
		return make_pair(p.first + v,p.second);
	}
	p = min(calc(il),calc(ir));
	return make_pair(p.first + v,p.second);
}

int main()
{
	char *tok;
	while(gets(str))
	{
		N = 0;
		tok = strtok(str," ");
		while(tok)
		{
			ii[N++] = atoi(tok);
			tok = strtok(NULL," ");
		}
		gets(str);
		N = 0;
		tok = strtok(str," ");
		while(tok)
		{
			ip[N++] = atoi(tok);
			tok = strtok(NULL," ");
		}
		nNode = 0;
		construct_tree(0,N-1,0,N-1);
		printf("%d\n",calc(0).second);
	}

	return 0;
}
