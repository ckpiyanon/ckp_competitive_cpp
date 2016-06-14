#include <bits/stdc++.h>

using namespace std;

int balance()	/// -1 if not else return total weight
{
	int wl,wr,dl,dr;
	scanf("%d %d %d %d",&wl,&dl,&wr,&dr);
	if(wl == 0)	wl = balance();
	if(wr == 0)	wr = balance();
	if(wl == -1 || wr == -1)	return -1;
	if(wl * dl == wr * dr)	return wl + wr;
	return -1;
}

int main()
{
	int TC;
	scanf("%d",&TC);
	char ans[2][5] = {"NO","YES"};
	for(int TC_ = 0;TC_ < TC;TC_++)
	{
		if(TC_)	printf("\n");
		printf("%s\n",ans[balance() != -1]);
	}

	return 0;
}
