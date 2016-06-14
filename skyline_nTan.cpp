#include <stdio.h>
int ta[3010];
main()
{
    int a,b,c,d,e=0,f,g,h,i,j,k,l,n,r,ct=0;
    scanf(" %d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %d %d %d",&l,&h,&r);
        for(j=l;j<r;j++)if(ta[j]<h)ta[j]=h;
        if(r>e)e=r;
    }
    for(i=0;i<=e;i++)
    {
        if(ta[i]!=ta[i+1])
        {
            printf("%d %d ",i+1,ta[i+1]);
            ct++;
        }
        //printf("%d ",ta[i]);
    }
}
