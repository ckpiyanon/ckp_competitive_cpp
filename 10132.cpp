#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int TC,tlen,n,match,k;
    vector<string> arr,arrL;
    string s;
    char cstr[3000];
    gets(cstr);
    TC = atoi(cstr);
    gets(cstr);
    while(TC--)
    {
        arr.clear();
        arrL.clear();
        tlen = 0;
        while(gets(cstr))
        {
            s = string(cstr);
            if(s == "")
                break;
            arr.push_back(s);
            tlen += s.size();
        }
        n = arr.size() / 2;
        tlen /= n;
        for(int i = 0;i < arr.size();i++)
        {
            for(int j = i+1;j < arr.size();j++)
            {
                if(arr[i].size() + arr[j].size() == tlen)
                    arrL.push_back(arr[i] + arr[j]),arrL.push_back(arr[j] + arr[i]);
            }
        }
        sort(arrL.begin(),arrL.end());
        k = 0;
        while(k < arrL.size())
        {
            s = arrL[k];
            match = 0;
            while(k < arrL.size() && s == arrL[k])
                match++,k++;
            if(match >= n)
            {
                cout << s << endl;
                k = arrL.size() + 10;
            }
        }
        if(TC > 0)
            cout << endl;
    }

    return 0;
}
