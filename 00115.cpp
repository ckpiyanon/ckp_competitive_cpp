#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph(400);
int deg[400],parent[400];

void dfs_fill(int u,int x)
{
	deg[u] = x;
	for(vector<int>::iterator it = graph[u].begin();it < graph[u].end();it++)
		dfs_fill(*it,x+1);
}
int main()
{
//	freopen("in.txt","r",stdin);
	map<string,int> ma;
	memset(parent,-1,sizeof(parent));
	string s1,s2;
	while(true)
	{
		cin >> s1 >> s2;
		if(s1 == "no.child" && s2 == "no.parent")	break;
		if(ma.find(s1) == ma.end())	ma.insert(make_pair(s1,ma.size()+1));
		if(ma.find(s2) == ma.end())	ma.insert(make_pair(s2,ma.size()+1));
		int p = ma[s1],q = ma[s2];
		parent[p] = q;
		graph[q].push_back(p);
	}
	for(int i = 0;i < ma.size();i++)
		if(parent[i] == -1)
			dfs_fill(i,1);
	while(cin >> s1 >> s2)
	{
		int p1 = ma[s1],p2 = ma[s2],rem = 0;
		if(p1 == p2 || !p1 || !p2)	cout << "no relation" << endl;
		else if(parent[p1] == parent[p2])	cout << "sibling" << endl;
		else if(parent[p1] == p2)	cout << "child" << endl;
		else if(p1 == parent[p2])	cout << "parent" << endl;
		else
		{
			while(deg[p1] > deg[p2])	p1 = parent[p1],rem++;
			while(deg[p2] > deg[p1])	p2 = parent[p2],rem--;
			if(p1 == p2)
			{
				int x = rem >= 0 ? rem:(-rem);
				for(int i = 2;i < x;i++)	cout << "great ";
				cout << "grand ";
				if(rem < 0)	cout << "parent";
				else	cout << "child";
				cout << endl;
			}
			else
			{
				if(rem < 0)	rem = -rem;
				int r1 = p1,r2 = p2,t = 0;
				while(r1 != 0 && r2 != 0 && r1 != r2)
					r1 = parent[r1],r2 = parent[r2],t++;
				if(r1 == r2 && r1 != 0 && r2 != 0)
				{
					cout << t-1 << " cousin";
					if(rem != 0)	cout << " removed " << rem;
					cout << endl;
				}
				else	cout << "no relation" << endl;
			}
		}
	}

	return 0;
}
