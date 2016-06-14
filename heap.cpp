#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

template<class _T> class heap
{
    private :
        vector<_T> arr;
        void heapify_top(int p)
        {
            int sz = arr.size();
            if(p*2 + 1 >= sz)
                return;
            if(p*2 + 2 >= sz)
            {
                if(arr[p] < arr[p*2 + 1])
                {
                    swap(arr[p],arr[p*2 + 1]);
                    heapify_top(p*2 + 1);
                }
            }
            else
            {
                if(arr[p] < arr[p*2 + 1])
                {
                    swap(arr[p],arr[p*2 + 1]);
                    heapify_top(p*2 + 1);
                }
                else if(arr[p] < arr[p*2 + 2])
                {
                    swap(arr[p],arr[p*2 + 2]);
                    heapify_top(p*2 + 2);
                }
            }
        }
        void heapify_bottom(int p)
        {
            if(p == 0)
                return;
            if(arr[p] > arr[p/2])
            {
                swap(arr[p],arr[p/2]);
                heapify_bottom(p/2);
            }
        }
    public :
        void add(_T n)
        {
            arr.push_back(n);
            heapify_bottom(arr.size()-1);
        }
        _T getTop()
        {
            return arr[0];
        }
        void pop()
        {
            _T n = arr.back();
            arr.pop_back();
            arr[0] = n;
            heapify_top(0);
        }
        bool empty()
        {
            return arr.empty();
        }
};

int main()
{
    heap<int> a;
    for(int i = 0;i < 10;i++)
        a.add(i+1);
    while(!a.empty())
    {
        printf("%d\n",a.getTop());
        a.pop();
    }

    return 0;
}
