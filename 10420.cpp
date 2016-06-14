#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    map<string,int> ma;
    set<string> se;
    int n;
    char s[76],*tok;
    scanf("%d ",&n);
    while(n--)
    {
        gets(s);
        tok = strtok(s," ");
        ma[string(tok)]++;
        se.insert(string(tok));
    }
    for(set<string>::iterator i = se.begin();i != se.end();i++)
        printf("%s %d\n",i -> c_str(),ma[*i]);

    return 0;
}
