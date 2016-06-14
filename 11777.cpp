#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int TC,score,inp,t[3];
	scanf("%d",&TC);
	for(int T = 1;T <= TC;T++)
	{
		score = 0;
		for(int i = 0;i < 4;i++)	scanf("%d",&inp),score += inp;
		for(int i = 0;i < 3;i++)	scanf("%d",t + i);
		if(t[0] < t[1])	swap(t[0],t[1]);
		if(t[1] < t[2])	swap(t[1],t[2]);
		if(t[0] < t[1])	swap(t[0],t[1]);
		score += (t[0] + t[1]) / 2;
		printf("Case %d: %c\n",T,score >= 90 ? 'A':(score >= 80 ? 'B':(score >= 70 ? 'C':(score >= 60 ? 'D':'F'))));
	}
}
