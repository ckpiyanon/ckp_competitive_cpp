#include <bits/stdc++.h>
#define MAXSIZE 1300

using namespace std;

int N,graph[MAXSIZE][MAXSIZE];
unordered_map<string,int> name_set,party_set,club_set;
bitset<MAXSIZE> visited;

int get(unordered_map<string,int> &ma,string &s)
{
	unordered_map<string,int>::iterator it = ma.find(s);
	if(it != ma.end())	return it->second;
	return ma[s] = ++N;
}
int source() {return 0;}
int target() {return 1;}

int maxflow(int s,int minn)
{
	int flow;
	visited[s] = true;
	if(s == target())	return minn;
	for(int i = 0;i <= N;i++)
	{
		if(!visited[i] && graph[s][i] > 0 && (flow = maxflow(i,min(minn,graph[s][i]))))
		{
			graph[s][i] -= flow;
			graph[i][s] += flow;
			return flow;
		}
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	string name,party,club;
	char ins[100],*ptr;
	int TC,tmp,ans;
	TC = atoi(gets(ins));
	gets(ins);
	while(TC--)
	{
		name_set.clear(); party_set.clear(); club_set.clear();
		memset(graph,0,sizeof(graph));
		N = 1;
		while(gets(ins) && strlen(ins))
		{
			ptr = strtok(ins," ");
			name = string(ptr);
			ptr = strtok(NULL," ");
			party = string(ptr);
			graph[get(name_set,name)][get(party_set,party)] = 1;
			while(ptr = strtok(NULL," "))
			{
				club = string(ptr);
				graph[source()][get(club_set,club)] = 1;
				graph[get(club_set,club)][get(name_set,name)] = 1;
			}
		}
		tmp = (club_set.size() - 1) / 2;
		for(unordered_map<string,int>::iterator it = party_set.begin();it != party_set.end();it++)
			graph[it->second][target()] = tmp;
		ans = 0;
		visited.reset();
		while(tmp = maxflow(source(),INT_MAX))
		{
			ans += tmp;
			visited.reset();
		}
		if(ans != club_set.size())	printf("Impossible.\n");
		else
			for(unordered_map<string,int>::iterator it_name = name_set.begin();it_name != name_set.end();it_name++)
			for(unordered_map<string,int>::iterator it_club = club_set.begin();it_club != club_set.end();it_club++)
				if(graph[it_name->second][it_club->second])
				{
					printf("%s %s\n",(it_name->first).c_str(),(it_club->first).c_str());
					break;
				}
		if(TC)	printf("\n");
	}

	return 0;
}
