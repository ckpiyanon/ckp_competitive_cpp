#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC,w,h,l;
	scanf("%d",&TC);
	for(int TC_ = 1;TC_ <= TC;TC_++)
	{
		scanf("%d %d %d",&w,&h,&l);
		printf("Case %d: %s\n",TC_,w > 20 || h > 20 || l > 20 ? "bad":"good");
	}

	return 0;
}
