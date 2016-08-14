#include <bits/stdc++.h>
using namespace std;

int n,mask_open,mask_visit;
int graph[15];

int count_ones(int bits)
{
    int num = 0;
    while(bits > 0) num += (bits & 1),bits = bits >> 1;
    return num;
}
bool is_one(int bits,int u) {return bits & (1 << u);}
bool is_zero(int bits,int u) {return !is_one(bits,u);}
bool is_ring(int u,int v)
{
    if(is_one(mask_visit,v))   return true;
    mask_visit |= (1 << v);
    for(int i = 0;i < n;i++)
        if(is_zero(mask_open,i) && is_one(graph[v],i) && i != u && is_ring(v,i))    return true;
    return false;
}

int main()
{
    int u,v,TC = 0,ans,num_open,num_strands;
    bool ok;
    while(scanf("%d",&n) != -1 && n)
    {
        memset(graph,0,sizeof(graph));
        ans = n;
        while(scanf("%d %d",&u,&v) != -1 && u != -1 && v != -1)
            u--,v--,graph[u] |= (1 << v),graph[v] |= (1 << u);
        for(mask_open = 0;mask_open < (1 << n);mask_open++)
        {
            num_open = count_ones(mask_open);
            num_strands = 0;
            mask_visit = 0;
            ok = true;
            for(int i = 0;i < n && ok;i++) if(is_zero(mask_open,i))
            {
                int deg = 0;
                for(int j = 0;j < n;j++) if(is_zero(mask_open,j) && is_one(graph[i],j))
                    deg++;
                ok = deg <= 2;
            }
            if(!ok) continue;
            for(int i = 0;i < n && ok;i++) if(is_zero(mask_open,i) && is_zero(mask_visit,i))
            {
                num_strands++;
                ok = !is_ring(-1,i);
            }
            if(ok && num_strands - 1 <= num_open)   ans = min(ans,num_open);
        }
        printf("Set %d: Minimum links to open is %d\n",++TC,ans);
    }

    return 0;
}
