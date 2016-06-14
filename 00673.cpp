#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s[150],ans[][5] = {"No\n","Yes\n"};
    int n,len;
    stack<char> st;
    scanf("%d ",&n);
    while(n--)
    {
        while(!st.empty())  st.pop();
        gets(s);
        len = strlen(s);
        for(int i = 0;i < len;i++)
        {
            if(st.empty() || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else if((st.top() == '[' && s[i] == ']') || (st.top() == '(' && s[i] == ')'))
                st.pop();
        }
        printf(ans[st.empty()]);
    }

    return 0;
}
