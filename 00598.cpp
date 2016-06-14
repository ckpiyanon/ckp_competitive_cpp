#include <cstdio>
#include <cstdlib>
#include <cstring>

char inputs[12][31];
int numS,mNum,idx[12];

void print()
{
    for(int i = 0;i < mNum;i++)
    {
        printf(inputs[idx[i]]);
        if(i < mNum - 1)    printf(", ");
    }
    printf("\n");
}
void play(int now,int next,int num)
{
    if(num == mNum)
    {
        print();
        return;
    }
    for(int i = next;i < numS;i++)
    {
        idx[now] = i;
        play(now + 1,i + 1,num + 1);
    }
}

int main()
{
    int TC,n,m;
    char s[50],*p;
    gets(s);
    TC = atoi(s);
    gets(s);
    while(TC--)
    {
        gets(s);
        p = strtok(s," ");
        n = atoi(p);
        if(p[0] != '*')
        {
            p = strtok(NULL," ");
            if(p)   m = atoi(p);
            else    m = n;
        }
        else    n = m = 0;
        numS = 0;
        gets(s);
        do
        {
            if(strcmp(s,""))    strcpy(inputs[numS++],s);
            else break;
        } while(gets(s));
        if(n == 0 && m == 0)    n = 1,m = numS;
        for(int i = n;i <= m;i++)
        {
            printf("Size %d\n",i);
            mNum = i;
            play(0,0,0);
            printf("\n");
        }
        if(TC)  printf("\n");
    }

    return 0;
}
