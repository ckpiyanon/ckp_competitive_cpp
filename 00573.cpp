#include <cstdio>

int main()
{
    double fh,h,u,d,f;
    int day;
    while(scanf("%lf %lf %lf %lf",&h,&u,&d,&f))
    {
        if(h == 0)
            break;
        fh = h;
        day = 0;
        f = u * f / 100.0;
        while(fh >= h)
        {
            if(u > 0)
                h -= u;
            day++;
            if(h < 0)
                break;
            h += d;
            u -= f;
        }
        if(h < 0)
            printf("success ");
        else
            printf("failure ");
        printf("on day %d\n",day);
    }

    return 0;
}
