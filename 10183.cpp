#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ncmp(string a,string b)
{
    if(a.size() < b.size()) return -1;
    if(a.size() > b.size()) return 1;
    int len = a.size();
    for(int i = 0;i < len;i++)
    {
        if(a[i] < b[i]) return -1;
        if(a[i] > b[i]) return 1;
    }
    return 0;
}

int addChar(char a,char b)
{
    return (a - '0') + (b - '0');
}

string addNumber(string a,string b)
{
    int len = max(a.size(),b.size());
    int sum,rem;
    string tmp = "",t;
    while(a.size() < len)
        a = '0' + a;
    while(b.size() < len)
        b = '0' + b;

    rem = 0;
    for(int i = 0;i < len;i++)
    {
        t = "";
        sum = rem + addChar(a[len-i-1],b[len-i-1]);
        rem = sum / 10;
        sum %= 10;
        t += '0' + sum;
        tmp = t + tmp;
    }
    if(rem)
        tmp = '1' + tmp;

    return tmp;
}

int main()
{
    vector<string> arr;
    string tmp,imax = "1";
    string inp[2];
    int ans;
    char s[110];

    for(int i = 0;i < 100;i++)
        imax += '0';
    arr.push_back("1");
    arr.push_back("2");
    tmp = "3";
    do
    {
        arr.push_back(tmp);
        tmp = addNumber(arr[arr.size()-2],arr[arr.size()-1]);
    }
    while(ncmp(tmp,imax) <= 0);

    scanf("%s",s);
    inp[0] = string(s);
    scanf("%s",s);
    inp[1] = string(s);
    while(inp[0] != "0" || inp[1] != "0")
    {
        ans = 0;
        for(vector<string>::iterator i = arr.begin();i != arr.end();i++)
        {
            if(ncmp(inp[0],*i) <= 0 && ncmp(inp[1],*i) >= 0)
                ans++;
        }
        printf("%d\n",ans);
        scanf("%s",s);
        inp[0] = string(s);
        scanf("%s",s);
        inp[1] = string(s);
    }

    return 0;
}
