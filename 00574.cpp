#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    char str[5000],*tok;
    int n,t;
    vector<int> arr,ch;
    while(gets(str))
    {
        tok = strtok(str," ");
        sscanf(tok,"%d",&n);
        if(n == 0)
            break;
        tok = strtok(NULL," ");
        arr.clear();
        ch.clear();
        while(tok)
        {
            sscanf(tok,"%d",&t);
            arr.push_back(t);
            ch.push_back(1);
            if(arr.at(arr.size()-1) > n)
                ch.at(arr.size()-1) = 0;
        }
    }

    return 0;
}
