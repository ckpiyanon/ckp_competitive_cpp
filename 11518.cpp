#include <cstdio>
#include <vector>
#include <queue>
#include <list>

using namespace std;

vector<vector<int> > graph;
bool *v;
int num_bfs(int head)
{
    int ans = 0;
    int t = head;
    queue<int> q;
    q.push(t);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(v[t])
            continue;
        ans++;
        v[t] = true;
        for(vector<int>::iterator i = graph[t].begin();i < graph[t].end();i++)
            if(!v[*i])
                q.push(*i);
    }
    return ans;
}

int main()
{
    int TC,n,m,l,t1,t2,ans;
    scanf("%d",&TC);
    while(TC--)
    {
        graph.clear();
        scanf("%d %d %d",&n,&m,&l);
        for(int i = 0;i < n;i++)
        {
            graph.push_back(vector<int>());
            graph[i].clear();
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d %d",&t1,&t2);
            graph[t1-1].push_back(t2-1);
        }
        v = new bool[graph.size()];
        for(int i = 0;i < graph.size();i++)
            v[i] = false;
        ans = 0;
        for(int i = 0;i < l;i++)
        {
            scanf("%d",&t1);
            ans += num_bfs(t1-1);
        }
        printf("%d\n",ans);
        delete[] v;
    }

    return 0;
}
