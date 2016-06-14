#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    char s[51];
    while(1)
    {
        gets(s);
        if(s[0] == '#')
            break;
        if(std::next_permutation(s,s+strlen(s)))
            puts(s);
        else
            puts("No Successor");
    }

    return 0;
}
