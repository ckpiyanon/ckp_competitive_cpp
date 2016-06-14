#include <cstdio>
#include <cstring>
#include <algorithm>
#define INS "Insert"
#define DEL "Delete"
#define REP "Replace"
#define M trace(r-1,c-1)
#define R trace(r-1,c-1),printf("%d %s %d,%c\n",++cnt,REP,r + ins - del,s2[c-1])
#define I trace(r,c-1),printf("%d %s %d,%c\n",++cnt,INS,r + 1 + ins - del,s2[c-1]),ins++
#define D trace(r-1,c),printf("%d %s %d\n",++cnt,DEL,r + ins - del),del++

using namespace std;

int cnt,ins,del,arr[81][81];
char s1[81],s2[81];
void trace(int r,int c)
{
	if(!arr[r][c])	return;
	int t;
	if(r != 0 || c != 0)
	{
		if(r == 0)	I;
		else if(c == 0)	D;
		else
		{
			t = min(arr[r-1][c],min(arr[r][c-1],arr[r-1][c-1]));
			if(t == arr[r][c])	M;
			else if(t == arr[r-1][c-1])	R;
			else if(t == arr[r-1][c])	D;
			else	I;
		}
	}
}
int main()
{
	int l1 = -1,l2;
	for(int i = 0;i <= 80;i++)	arr[i][0] = arr[0][i] = i;
	while(gets(s1))
	{
		if(l1 != -1)	printf("\n");
		l1 = strlen(s1);
		l2 = strlen(gets(s2));
		for(int i = 1;i <= l1;i++)	for(int j = 1;j <= l2;j++)
			arr[i][j] = s1[i-1] == s2[j-1] ? arr[i-1][j-1]:(min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1])) + 1);
		cnt = ins = del = 0;
		printf("%d\n",arr[l1][l2]);
		trace(l1,l2);
	}
	return 0;
}
