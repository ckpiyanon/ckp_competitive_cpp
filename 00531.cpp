#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[100][31],s2[100][31];
int sz1,sz2;
int arr[101][101];

void trace(int r,int c)
{
	int t = arr[r][c];
	if(t == 0)	return;
	while(arr[r-1][c] == t)	r--;
	while(arr[r][c-1] == t)	c--;
	trace(r-1,c-1);
	printf("%s",s1[r-1]);
	printf("%c",t == arr[sz1][sz2] ? '\n':' ');
}

int main()
{
	bool x;
	while(1)
	{
		sz1 = sz2 = 0;
		while(1)
		{
			x = scanf("%s",s1[sz1]) != EOF;
			if(s1[sz1][0] == '#' || !x)	break;
			sz1++;
		}
		while(x)
		{
			scanf("%s",s2[sz2]);
			if(s2[sz2][0] == '#')	break;
			sz2++;
		}
		if(!x)	break;
		for(int i = 1;i <= sz1;i++)	for(int j = 1;j <= sz2;j++)
			arr[i][j] = strcmp(s1[i-1],s2[j-1]) == 0 ? (arr[i-1][j-1] + 1):(max(arr[i-1][j-1],max(arr[i][j-1],arr[i-1][j])));
		trace(sz1,sz2);
	}

	return 0;
}
