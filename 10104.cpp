#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    int x,y,a,c,s[3][2];
    while(~scanf("%d %d",&x,&y))
    {
        memset(s,0,sizeof(s));
        s[0][0] = s[1][1] = 1;
        while(x % y)
        {
            a = x / y;
            c = x % y;
            s[2][0] = s[0][0] - a*s[1][0];
            s[2][1] = s[0][1] - a*s[1][1];
            s[0][0] = s[1][0],s[0][1] = s[1][1];
            s[1][0] = s[2][0],s[1][1] = s[2][1];
            x = y,y = c;
        }
        printf("%d %d %d\n",s[1][0],s[1][1],y);
    }

    return 0;
}
