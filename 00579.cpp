#include <cmath>
#include <cstdio>

int main()
{
    int a,b;
    double ans;
    while(true)
    {
        scanf("%d:%d",&a,&b);
        if(!a && !b)
            break;
        a %= 12;
        ans = fabs(((a * 30.0) + (b / 2.0)) - (b * 6.0));
        printf("%.3lf\n",ans > 180 ? (360 - ans):ans);
    }

    return 0;
}
