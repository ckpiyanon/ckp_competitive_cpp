#include <stack>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    int j,k;
    int arr[1000];
    stack<int> st;
    while(true)
    {
        scanf("%d",&n);
        if(n == 0)	break;
        while(true)
        {
            while(!st.empty())
                st.pop();
            scanf("%d",arr);
            if(arr[0] == 0)	break;
            for(int i = 1;i < n;i++)	scanf("%d",arr+i);
            j = 0,k = 1;
            while(k <= n)
            {
                st.push(k);
                while(!st.empty() && st.top() == arr[j])
                {
                    st.pop();
                    j++;
                    if(j >= n)	break;
                }
                k++;
            }
            if(st.empty())	printf("Yes\n");
            else	printf("No\n");
        }
        printf("\n");
    }

    return 0;
}
