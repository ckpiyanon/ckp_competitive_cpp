#include <cstdio>
#include <algorithm>
int main()
{
	int arr[] = {561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973};
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n)	break;
		if(std::binary_search(arr,arr + 15,n))
			printf("The number %d is a Carmichael number.\n",n);
		else
			printf("%d is normal.\n",n);
	}

	return 0;
}
