#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

map<char,char> ma;

bool palin(char *s)
{
    int len = strlen(s);
    for(int i = 0;i < len/2;i++)
    {
        if(s[i] != s[len-i-1])
            return false;
    }
    return true;
}
bool mirror(char *s)
{
    int len = strlen(s);
    for(int i = 0;i <= len/2;i++)
    {
        if(ma[s[i]] != s[len-i-1])
            return false;
    }
    return true;
}

int main()
{
    ma['A'] = 'A';
    ma['E'] = '3';
    ma['H'] = 'H';
    ma['I'] = 'I';
    ma['J'] = 'L';
    ma['L'] = 'J';
    ma['M'] = 'M';
    ma['O'] = 'O';
    ma['S'] = '2';
    ma['T'] = 'T';
    ma['U'] = 'U';
    ma['V'] = 'V';
    ma['W'] = 'W';
    ma['X'] = 'X';
    ma['Y'] = 'Y';
    ma['Z'] = '5';
    ma['1'] = '1';
    ma['2'] = 'S';
    ma['3'] = 'E';
    ma['5'] = 'Z';
    ma['8'] = '8';

    char s[21];
    bool pa,mi;
    while(scanf("%s",s) != EOF)
    {
        pa = palin(s);
        mi = mirror(s);
        if(pa && mi)
            printf("%s -- is a mirrored palindrome.",s);
        else if(pa)
            printf("%s -- is a regular palindrome.",s);
        else if(mi)
            printf("%s -- is a mirrored string.",s);
        else
            printf("%s -- is not a palindrome.",s);
        printf("\n\n");
    }

    return 0;
}
