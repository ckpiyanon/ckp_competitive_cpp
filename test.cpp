#include <bits/stdc++.h>
#define SIZE 8
using namespace std;
int main()
{
	bool arr[SIZE];
	for(int i = 0;i < SIZE;i++)
		arr[i] = false;
	for(int i = 0;i < SIZE / 2;i++)
	{
		int pos = 1;
		while(pos < SIZE / 2)
		{
			arr[pos] = !arr[pos];
			pos = pos * 2 + !arr[pos];
		}
		printf("%d\n",pos);
	}

	return 0;
}
