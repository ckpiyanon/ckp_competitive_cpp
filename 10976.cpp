#include <cstdio>
#include <vector>
#include <utility>
#define X first
#define Y second

using namespace std;

typedef vector<pair<int,int> > vii;
int main()
{
	int n,a,b;
	vii arr;
	while(scanf("%d",&n) != EOF)
	{
		arr.clear();
		a = n + n;
		for(int i = n + 1;i <= a;i++)
		{
			if((n * i) % (i - n) == 0)	arr.push_back(make_pair((n * i) / (i - n),i));
		}
		printf("%d\n",arr.size());
		for(vii::iterator i = arr.begin();i < arr.end();i++)
			printf("1/%d = 1/%d + 1/%d\n",n,i -> X,i -> Y);
	}

	return 0;
}
