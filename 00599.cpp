#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef vector<int> vi;

vi graph[26];
bool v[26];

int dfs(int n)
{
    if(v[n])    return 0;
    int ans = 1,sz = graph[n].size();
    v[n] = true;
    for(int i = 0;i < sz;i++)  ans += dfs(graph[n][i]);
    return ans;
}

int main()
{
    int TC,len,t,aT,aA;
    char s[100];
    TC = atoi(gets(s));
    while(TC--)
    {
        memset(v,0,26);
        for(int i = 0;i < 26;i++)   graph[i].clear();
        while(1)
        {
            gets(s);
            if(s[0] == '*') break;
            graph[s[1] - 'A'].push_back(s[3] - 'A');
            graph[s[3] - 'A'].push_back(s[1] - 'A');
        }
        len = strlen(gets(s));
        aT = aA = 0;
        for(int i = 0;i < len;i += 2)
        {
            if(v[s[i] - 'A'])   continue;
            t = dfs(s[i] - 'A');
            if(t == 1)  aA++;
            else        aT++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n",aT,aA);
    }

    return 0;
}
