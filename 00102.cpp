#include <cstdio>
#include <cstring>
#include <climits>

int main()
{
    int bin[3][3],seq[6][3] = {{0,2,1},{0,1,2},{2,0,1},{2,1,0},{1,0,2},{1,2,0}},mm,total,sum;
    char ansS[6][4] = {"BCG","BGC","CBG","CGB","GBC","GCB"},inp[200],*ansF,*p;
    while(gets(inp))
    {
        int i = 0;
        total = 0;
        p = strtok(inp," ");
        while(p)
        {
            sscanf(p,"%d",&bin[i/3][i%3]);
            total += bin[i/3][i%3];
            p = strtok(NULL," ");
            i++;
        }
        mm = INT_MAX;
        for(int i = 0;i < 6;i++)
        {
            sum = total;
            for(int j = 0;j < 3;j++)    sum -= bin[j][seq[i][j]];
            if(sum < mm)    mm = sum,ansF = ansS[i];
        }
        printf("%s %d\n",ansF,mm);
    }

    return 0;
}
