#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

vector<vector<ii> > graph;
set<int> fs;

int numi,numf,weight[500];

int sssp(int tu)
{
    for(int i = 0;i < 500;i++)  weight[i] = -1;
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,tu));
    for(set<int>::iterator it = fs.begin();it != fs.end();it++)
        pq.push(ii(0,*it));
    while(!pq.empty())
    {
        ii edge = pq.top();
        pq.pop();
        if(weight[edge.second] == -1)
        {
            weight[edge.second] = edge.first;
            for(vector<ii>::iterator it = graph[edge.second].begin();it < graph[edge.second].end();it++)
            {
                pq.push(ii(weight[edge.second] + (it->first),it->second));
            }
        }
    }
    int m = INT_MIN;
    for(int i = 0;i < numi;i++)
    {
        m = max(m,weight[i]);
    }
    return m;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int f,u,v,w;
    char inp[101];
    int TC = atoi(gets(inp));
    gets(inp);
    while(TC--)
    {
        graph.assign(500,vector<ii>());
        fs.clear();
        gets(inp);
        numf = atoi(strtok(inp," "));
        numi = atoi(strtok(NULL," "));
        for(int i = 0;i < numf;i++) {
            fs.insert(atoi(gets(inp)) - 1);
        }
        while(gets(inp) && strlen(inp))
        {
            u = atoi(strtok(inp," ")) - 1;
            v = atoi(strtok(NULL," ")) - 1;
            w = atoi(strtok(NULL," "));
            graph[u].push_back(ii(w,v));
            graph[v].push_back(ii(w,u));
        }
        int m = 1000000000;
        u = 0;
        for(int i = 0;i < numi;i++) if(fs.find(i) == fs.end())
        {
            w = sssp(i);
            if(w < m)
            {
                m = w;
                u = i;
            }
        }
        printf("%d\n",u + 1);
        if(TC)  printf("\n");
    }

    return 0;
}
