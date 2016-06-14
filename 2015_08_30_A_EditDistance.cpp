#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[2010][2010];
char s1[2010],s2[2010];
int main()
{
	int l1,l2,TC;
	scanf("%d ",&TC);
	for(int i = 0;i <= 2000;i++)	arr[i][0] = arr[0][i] = i;
	while(TC--)
	{
		gets(s1);
		gets(s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		for(int i = 1;i <= l1;i++)	for(int j = 1;j <= l2;j++)
			arr[i][j] = s1[i-1] == s2[j-1] ? arr[i-1][j-1]:(min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1])) + 1);
		printf("%d\n",arr[l1][l2]);
	}
	return 0;
}
