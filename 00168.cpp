#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph(26);
int minotaur,theseus,k;
bitset<26> candle;

void gen_graph(char *s)
{
	char u = s[0] - 'A';
	graph.assign(26,vector<int>());
	for(int i = 1;s[i];i++)
	{
		if(s[i] == ':' || s[i] == '.')	continue;
		if(s[i] == ';')	u = s[++i] - 'A';
		else	graph[u].push_back(s[i] - 'A');
	}
}

int flee()
{
	for(vector<int>::iterator it = graph[minotaur].begin();it != graph[minotaur].end();it++)
		if(*it != theseus && !candle[*it])	return *it;
	return -1;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char s[300];
	int t,cav;
	while(gets(s))
	{
		if(s[0] == '#')	break;
		gen_graph(strtok(s," "));
		minotaur = strtok(NULL," ")[0] - 'A';
		theseus = strtok(NULL," ")[0] - 'A';
		k = atoi(strtok(NULL," "));
		cav = 0;
		candle.reset();
		while(true)
		{
			t = flee();
			if(cav == k)
			{
				printf("%c ",theseus + 'A');
				candle.set(theseus);
				cav = 0;
			}
			cav++;
			if(t == -1)
			{
				printf("/%c\n",minotaur + 'A');
				break;
			}
			else
			{
				theseus = minotaur;
				minotaur = t;
			}
		}
	}

	return 0;
}
