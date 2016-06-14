#include <list>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>

#define ZERO 1e-10

using namespace std;

bool eq(double a,double b)
{
    return fabs(a-b) < ZERO;
}

class point
{
public :
    double lE,rE,tp;
    point(double a,double b,double c)
    {
        this -> lE = a;
        this -> rE = b;
        this -> tp = c;
    }
};
bool operator < (point a,point b)
{
    if(eq(a.lE,b.lE))
        return a.rE < b.rE;
    return a.lE < b.lE;
}

int main()
{
    vector<double> vd;
    vector<point> vp,va;
    point pt(1,1,1);
    double a,b,c,t;
    int q,n,j;
    scanf("%d",&q);
    while(q--)
    {
        vd.clear();
        vp.clear();
        va.clear();
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%lf %lf %lf %lf %lf",&a,&t,&b,&t,&c);
            if(a > b)
                swap(a,b);
            vd.push_back(a);
            vd.push_back(b);
            vp.push_back(point(a,b,c));
        }
        sort(vd.begin(),vd.end());
        for(int i = 0;i < vd.size()-1;i++)
        {
            if(eq(vd[i],vd[i+1]))
                continue;
            va.push_back(point(vd[i],vd[i+1],1.0));
        }
        for(int i = 0;i < vp.size();i++)
        {
            j = 0;
            while(!eq(va[j].lE,vp[i].lE))   j++;
            do
            {
                va[j++].tp *= vp[i].tp;
                if(j == va.size())
                    break;
            }while(va[j].rE <= vp[i].rE);
        }
        printf("%d\n",va.size()+2);
        printf("-inf %.3lf 1.000\n",vd.front());
        for(int i = 0;i < va.size();i++)
            printf("%.3lf %.3lf %.3lf\n",va[i].lE,va[i].rE,va[i].tp);
        pt = vp.back();
        printf("%.3lf +inf 1.000\n",vd.back());
        if(q)
            printf("\n");
    }

    return 0;
}
