#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n,p,prop,cnt = 0;
    double com,pri,_pri;
    char name[101],ans[101],t[101];
    scanf("%d %d ",&n,&p);
    while(n != 0 && p != 0)
    {
        com = 0,pri = 2000000000;
        for(int i = 0;i < n;i++)
            gets(t);
        for(int i = 0;i < p;i++)
        {
            gets(name);
            scanf("%lf %d ",&_pri,&prop);
            for(int i = 0;i < prop;i++)
                gets(t);
            if((double)prop / (double)p > com || ((double)prop / (double)p == com && _pri < pri))
            {
                strcpy(ans,name);
                com = (double)prop / (double)p;
                pri = _pri;
            }
        }
        printf("RFP #%d\n",++cnt);
        printf("%s\n",ans);
        scanf("%d %d ",&n,&p);
        if(n != 0 && p != 0)	printf("\n");
    }

    return 0;
}
