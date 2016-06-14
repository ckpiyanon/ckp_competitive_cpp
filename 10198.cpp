#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char arr[1001][450];
char zero[] = "0",one[] = "1",two[] = "2",three[] = "3";
char zeroes[450];
void plus_string(char *a,char *b)
{
	int l1 = strlen(a),l2 = strlen(b),m = max(l1,l2),car = 0,sum;
	if(l2 > l1)
	{
		for(int i = l1;i < l2;i++)
			a[i] = '0';
		a[l2] = '\0';
	}
	for(int i = 0;i < m;i++)
	{
		sum = a[i] + b[i] + car - '0' - '0';
		car = sum / 10;
		a[i] = '0' + (sum % 10);
	}
	if(car > 0)
	{
		a[l2] = car + '0';
		a[l2 + 1] = '\0';
	}
}
char *play(char *s)
{
	if(n <= 0)	return zero;
	if(n == 1)	return two;
	if(strlen(arr[n]))	return arr[n];
	plus_string(arr[n],play(n-1) * 2);
	plus_string(arr[n],play(n-2));
	plus_string(arr[n],play(n-3));
}
void printi(char *s)
{
	int l = strlen(s);
	for(int i = l-1;i >= 0;i--)
		printf("%c",s[i]);
	printf("\n");
}
int main()
{
	while(scanf("%d",&n) != EOF)	printi(arr[n]);

	return 0;
}
