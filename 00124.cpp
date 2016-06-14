#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[26];
int w[26],ans[30],n;

void dfs(int idx)
{
	if(idx == n)
	{
		for(int i = 0;i < n;i++)	printf("%c",ans[i] + 'a');
		printf("\n");
		return;
	}
	for(int i = 0;i < 26;i++)
	{
        if(w[i] == 0)
        {
        	ans[idx] = i;
        	w[i]--;
        	for(int j = 0;j < graph[i].size();j++)	w[graph[i][j]]--;
        	dfs(idx + 1);
        	w[i]++;
        	for(int j = 0;j < graph[i].size();j++)	w[graph[i][j]]++;
        }
	}
}

int main()
{
	int len,f,t,d = 0;
	char inp[1000],*p;
	p = gets(inp);
	while(1)
	{
		if(!p)	break;
		len = strlen(inp);
		n = (len / 2) + 1;
		for(int i = 0;i < 26;i++)	w[i] = -1,graph[i].clear();
		for(int i = 0;i < len;i++)	w[inp[i] - 'a'] = 0;
		len = strlen(gets(inp));
		for(int i = 0;i < len;i += 4)
		{
			f = inp[i] - 'a',t = inp[i + 2] - 'a';
			graph[f].push_back(t);
			w[t]++;
		}
		dfs(0);
		p = gets(inp);
		if(p)	printf("\n");
	}

	return 0;
}
