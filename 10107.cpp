#include <set>
#include <cstdio>

std::multiset<long long> se;

int getAt(int n)
{
    std::multiset<long long>::iterator i = se.begin();
    while(n--)
        i++;
    return *i;
}

int main()
{
    long long n,e1,e2;
    while(scanf("%lld",&e1) != EOF)
    {
        se.insert(e1);
        n = se.size();
        if(n == 1)
            printf("%lld\n",*se.begin());
        else if(n%2 == 1)
            printf("%lld\n",getAt(n/2));
        else
        {
            e1 = getAt(n/2 - 1);
            e2 = getAt(n/2);
            printf("%lld\n",(e1 + e2)/2);
        }
    }

    return 0;
}
