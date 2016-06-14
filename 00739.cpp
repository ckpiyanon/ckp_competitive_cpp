#include <cstdio>
#include <cstring>
#include <cctype>

int val(char ch)
{
    ch = toupper(ch);
    switch(ch)
    {
        case 'B' : case 'P' : case 'F' : case 'V' :
            return 1;
        case 'C' : case 'S' : case 'K' : case 'G' : case 'J' : case 'Q' : case 'X' : case 'Z' :
            return 2;
        case 'D' : case 'T' :
            return 3;
        case 'L' :
            return 4;
        case 'M' : case 'N' :
            return 5;
        case 'R' :
            return 6;
    }
    return 0;
}
bool foo(char a,char b)
{
    if(a - b == 'a' - 'A' || b - a == 'a' - 'A')
        return true;
    return false;
}

int main()
{
    char name[100];
    int len,k;
    for(int i = 0;i < 9;i++)
        printf(" ");
    k = printf("NAME");
    for(int i = k;i < 25;i++)
        printf(" ");
    printf("SOUNDEX CODE\n");
    while(gets(name))
    {
        len = strlen(name);
        k = 1;
        for(int i = 0;i < 9;i++)
            printf(" ");
        k = printf("%s",name);
        for(int i = k;i < 25;i++)
            printf(" ");
        printf("%c",name[0]);
        k = 0;
        for(int i = 1;i < len;i++)
        {
            if(val(name[i]) != 0 && (val(name[i]) != val(name[i-1]) || foo(name[i],name[i-1])))
                printf("%c",'0' + val(name[i])),k++;
            if(k == 3)
                break;
        }
        if(k < 3)
        {
            for(int i = k;i < 3;i++)
                printf("0");
        }
        printf("\n");
    }
    for(int i = 0;i < 19;i++)
        printf(" ");
    printf("END OF OUTPUT\n");

    return 0;
}
