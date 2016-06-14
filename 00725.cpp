#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[30240],arr_sz = 0;
bool mark[10];
char m[10];

void permute(int s,int n)
{
	if(!n)
	{
		arr[arr_sz++] = s;
		return;
	}
	for(int i = 0;i < 10;i++)
	{
		if(!mark[i])
		{
			mark[i] = true;
			permute(s * 10 + i,n-1);
			mark[i] = false;
		}
	}
}

bool check(int a,int b)
{
	sprintf(m,"%05d%05d",a,b);
	sort(m,m+10);
	return strcmp(m,"0123456789") == 0;
}

int main()
{
	int n;
	bool found;
	memset(mark,0,10);
	permute(0,5);
	sort(arr,arr + arr_sz);
	scanf("%d",&n);
	while(1)
	{
		if(!n)	break;
		found = false;
		for(int i = 0;i < 30240;i++)
			if(arr[i] % n == 0 && check(arr[i],arr[i] / n))
				printf("%05d / %05d = %d\n",arr[i],arr[i] / n,n),found = true;
		if(!found)	printf("There are no solutions for %d.\n",n);
		scanf("%d",&n);
		if(n)	printf("\n");
	}

	return 0;
}
