#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

long long fact[21];
vector<char> li;

int main()
{
	vector<char>::iterator it;
    char s[21];
    int len,q,t;
    long long n;
    fact[0] = 1;
    for(int i = 1;i < 21;i++)	fact[i] = i * fact[i-1];
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s %lld",s,&n);
        len = strlen(s);
        sort(s,s + len);
		li.clear();
		for(int i = 0;i < len;i++)	li.push_back(s[i]);
        for(int i = 0;i < len;i++)
		{
			t = (int)(n / fact[len-i-1]);
			s[i] = li[t];
			li.erase(li.begin() + t);
			n %= fact[li.size()];
		}
        puts(s);
    }

    return 0;
}
