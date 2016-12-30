#include <bits/stdc++.h>

using namespace std;

int main()
{
	int arr[] = {1,1,1,2,2};
	int i = 1;
	while(next_permutation(arr,arr + 5))	i++;
	printf("%d\n",i);

	return 0;
}
