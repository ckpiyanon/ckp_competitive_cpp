#include <bits/stdc++.h>
using namespace std;
int dr[] = {-1,-1,1,1,-2,-2,2,2};
int dc[] = {-2,2,-2,2,-1,1,-1,1};
int di[] = {-7,-3,3,7,-11,-9,9,11};
class node {
public:
	string s;
	int w,p;
	node(string s,int w,int p):s(s),w(w),p(p) {}
	node move(int mv)
	{
		int np = p + mv;
		string ns = s;
		swap(ns[p],ns[np]);
		return node(ns,w+1,np);
	}
};
int main()
{
	unordered_map<string,int> moves;
	queue<node> q;
	q.push(node("111110111100 110000100000",0,12));
	moves["111110111100 110000100000"] = 0;
	while(!q.empty())
	{
		node n = q.front(); q.pop();
		if(n.w == 10)	continue;
		int r = n.p / 5,c = n.p % 5;
		for(int i = 0;i < 8;i++)
		{
			int nr = r + dr[i],nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= 5 || nc >= 5)	continue;
			node m = n.move(di[i]);
			if(moves.find(m.s) == moves.end())	moves[m.s] = m.w,q.push(m);
		}
	}
	char is[101],s[101];
	int TC = atoi(gets(s));
	while(TC--)
	{
		s[0] = '\0';
		for(int i = 0;i < 5;i++)	gets(is),strcat(s,is);
		if(moves.find(s) == moves.end())	printf("Unsolvable in less than 11 move(s).\n");
		else	printf("Solvable in %d move(s).\n",moves[s]);
	}

	return 0;
}
