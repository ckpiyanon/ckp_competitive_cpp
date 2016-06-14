#include <bits/stdc++.h>

using namespace std;

int arr[10000];

void traverse(int b,int e)
{
	int p = b,node = arr[b];
	while(arr[p] <= node && p <= e)	p++;
	if(p-1 != b)	traverse(b+1,p-1);
	if(p <= e)		traverse(p,e);
	printf("%d\n",node);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n = 0;
	while(scanf("%d",arr+n) != EOF)	n++;
	traverse(0,n-1);

	return 0;
}
