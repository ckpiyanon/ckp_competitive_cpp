#include <cstdio>
#include <cstring>

int TC,len,arr[5001][5001],mmax;
char s[5001];
int fmax(int a,int b) {return a > b ? a:b;}
int main()
{
	scanf("%d ",&TC);
	while(TC--)
	{
		len = strlen(gets(s));
		mmax = 0;
		for(int i = 1;i <= len;i++)
			for(int j = 1;j <= len;j++)
			{
				if(s[i-1] == s[j-1] && i != j)
					mmax = fmax(mmax,arr[i][j] = arr[i-1][j-1] + 1);
				else	arr[i][j] = 0;
			}
		printf("%d\n",mmax);
	}

	return 0;
}
