#include <cstdio>
#define max(a,b) (a > b ? a : b)

int mic[1000000];

int play(long long n)
{
    if(n < 1000000 && mic[n])   return mic[n];
    if(n == 1)                  return 1;
    if(n < 1000000)
    {
        if(n % 2)   mic[n] = 1 + play(3*n + 1);
        else        mic[n] = 1 + play(n/2);
        return mic[n];
    }
    if(n % 2)                   return 1 + play(3*n + 1);
    return 1 + play(n/2);
}

int main()
{
    bool chk;
    int a,b,ansR;
    while(scanf("%d %d",&a,&b) != EOF)
    {
        chk = false;
        if(a > b)
            a ^= b,b ^= a,a ^= b,chk = true;
        ansR = 0;
        for(int i = a;i <= b;i++)
            ansR = max(ansR,play(i));
        printf("%d %d %d\n",chk ? b:a,chk ? a:b,ansR);
    }

    return 0;
}
