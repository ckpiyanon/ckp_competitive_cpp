#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> graph(50000);
vector<int> storage(50000);
bool v[50000];

void dfs(int u)
{
    if(storage[u] >= 0) return;
    vector<int> vertex;
    int x,e;
    vertex.push_back(u);
    v[u] = true;
    u = graph[u];
    while(u != -1 && !v[u])
    {
        vertex.push_back(u);
        v[u] = true;
        u = graph[u];
    }
    e = vertex.size() - 1;
    if(u == -1)                 storage[vertex.back()] = 1;
    else if(storage[u] >= 0)    storage[vertex.back()] = storage[u] + 1;
    else
    {
        e = 0;
        while(vertex[e] != u)   e++;
        x = vertex.size() - e;
        for(int i = e;i < vertex.size();i++)    storage[vertex[i]] = x;
    }
    for(int i = e-1;i >= 0;i--)  storage[vertex[i]] = 1 + storage[vertex[i+1]];
}

int main()
{
    int TC,q,m,n,max_inp,max_ans,ans;
    scanf("%d",&TC);
    for(int nth = 1;nth <= TC;nth++)
    {
        max_ans = max_inp = INT_MIN;
        scanf("%d",&q);
        // init
        graph.assign(50000,-1);
        storage.assign(50000,-1);
        memset(v,false,50000);
        while(q--)
        {
            scanf("%d %d",&m,&n);
            max_inp = max(max_inp,max(m,n));
            graph[m-1] = n-1;
        }
        for(int i = 0;i < max_inp;i++)  dfs(i);
        for(int i = 0;i < max_inp;i++)  if(max_ans < storage[i]) ans = i,max_ans = storage[i];
        printf("Case %d: %d\n",nth,ans+1);
    }

    return 0;
}
