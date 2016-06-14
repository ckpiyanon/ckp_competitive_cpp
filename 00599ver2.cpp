#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int edge[26];
int num_edge[26];

bool cmp(int a,int b)
{
    return a > b;
}
int play(int tail)
{
    if(edge[tail] == tail)
        return tail;
    return play(edge[tail]);
}

int main()
{
    int TC,t,tree,acorn;
    char s[100],*tok;
    gets(s);
    TC = atoi(s);
    while(TC--)
    {
        for(int i = 0;i < 26;i++)
            edge[i] = -1;
        gets(s);
        while(s[0] != '*')
        {
            edge[max(s[1] - 'A',s[3] - 'A')] = min(s[1] - 'A',s[3] - 'A');
            gets(s);
        }
        gets(s);
        tok = strtok(s,",");
        while(tok)
        {
            if(edge[tok[0] - 'A'] == -1)
                edge[tok[0] - 'A'] = tok[0] - 'A';
            tok = strtok(NULL,",");
        }
        for(int i = 0;i < 26;i++)
            num_edge[i] = 0;
        for(int i = 0;i < 26;i++)
        {
            if(edge[i] > -1)
                num_edge[play(edge[i])]++;
        }
        tree = acorn = 0;
        for(int i = 0;i < 26;i++)
        {
            if(num_edge[i] > 1)
                tree++;
            else if(num_edge[i] == 1)
                acorn++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
    }

    return 0;
}
