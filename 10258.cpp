#include <cstdio>
#include <vector>
#include <algorithm>

class contestant
{
public :
    int prob,time,id;
    contestant()
    {
        prob = time = id = 0;
    }
    contestant(int id)
    {
        this -> id = id;
        prob = time = 0;
    }
};
class judge
{
public :
    int id,prob,time;
    char ch;
    judge(int id,int prob,int time,char ch)
    {
        this -> id = id;
        this -> prob = prob;
        this -> time = time;
        this -> ch = ch;
    }
};

int main()
{
    vector<judge> arrJ;
    vector<contestant> arrC;
    int q;
    int id,prob,time;
    char s[101],ch;
    scanf("%d ",&q);
    gets(s)
    while(q--)
    {
        arrJ.clear();
        arrC.clear();
        while(gets(s))
        {
            sscanf(s,"%d %d %d %c",&id,&prob,&time,&ch);
            if(ch != 'C' && ch != 'I')
                continue;
            arrJ.push_back(judge(id,prob,time,ch));
        }
        sort(arrJ.begin(),arrJ.end());
        for(int i = 0;i < arrJ.size();i++)
        {
            if(i == 0)
            {
                arrC.push_back(contestant(arrJ[i].id));
                if(arr[j])
            }
        }
    }

    return 0;
}
