#include <queue>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;
typedef vector<pair<int,int> > vii;

int weight[20000];
vii arrN[20000];

void bfs(int n)
{
    int ti,tw;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        n = q.front();
        q.pop();
        for(int i = 0;i < arrN[n].size();i++)
        {
            ti = arrN[n][i].first;
            tw = arrN[n][i].second;
            if(weight[ti] <= weight[n] + tw)    continue;
            weight[ti] = weight[n] + tw;
            q.push(ti);
        }
    }
}

int main()
{
    int TC,n,m,S,T,t1,t2,t3;
    scanf("%d",&TC);
    for(int _TC = 1;_TC <= TC;_TC++)
    {
        scanf("%d %d %d %d",&n,&m,&S,&T);
        for(int i = 0;i < n;i++)    weight[i] = 2000000000,arrN[i].clear();
        weight[S] = 0;
        for(int i = 0;i < m;i++)
        {
            scanf("%d %d %d",&t1,&t2,&t3);
            arrN[t1].push_back(make_pair(t2,t3));
            arrN[t2].push_back(make_pair(t1,t3));
        }
        bfs(S);
        printf("Case #%d: ",_TC);
        if(weight[T] != 2000000000) printf("%d\n",weight[T]);
        else    printf("unreachable\n");
    }

    return 0;
}
