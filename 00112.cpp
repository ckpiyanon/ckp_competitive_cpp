#include <bits/stdc++.h>
using namespace std;
bool yes; int total; char ch;
int tree(int sum)
{
	scanf(" %c",&ch);
	if(ch == '(')	scanf(" %c",&ch);
	if(ch == ')')	return -1;
	int num = ch - '0';
//	cout << "******" << ch << endl;
	while(scanf(" %c",&ch) != EOF && isdigit(ch))
	{
//		cout << "***" << ch << endl;
		num = num * 10 + ch - '0';
	}
//	cout << num << endl;
	sum += num;
	int l = tree(sum);
	while(scanf(" %c",&ch) != EOF && ch == ')');
	int r = tree(sum);
	if(sum == total && l == -1 && r == -1)	yes = true;
	return 0;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(~scanf("%d",&total))
	{
		scanf(" %c",&ch);
		yes = false;
		tree(0);
		printf("%s\n",yes ? "yes":"no");
	}
	return 0;
}
