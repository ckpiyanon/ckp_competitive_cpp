#include <bits/stdc++.h>
using namespace std;
char arr[10][11];
int n;
bool match(char *a,char *b)
{
	int len = strlen(a);
	for(int i = 0;i < len;i++)
		if(a[i] != b[i])
			return false;
	return true;
}
bool has_prefix()
{
	for(int i = 1;i < n;i++)
		if(strlen(arr[i-1]) < strlen(arr[i]) && match(arr[i-1],arr[i]))
			return true;
	return false;
}
bool cmp(char *a,char *b) {return strcmp(a,b) < 0;}
int main()
{
	freopen("in.txt","r",stdin);
	int TC = 0;
	char ans[][5] = {""," not"};
	while(!feof(stdin))
	{
		n = 0;
		while(true)
		{
			gets(arr[n++]);
			if(arr[n-1][0] == '9')
			{
				n--;
				break;
			}
		}
		sort(arr,arr + n,cmp);
		printf("Set %d is%s immediately decodable\n",++TC,ans[has_prefix()]);
	}

	return 0;
}
