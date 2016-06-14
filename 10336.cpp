#include <bits/stdc++.h>
using namespace std;
char arr[1000][1000];
const int dr[] = {-1,0,1,0},dc[] = {0,-1,0,1};
int n,m,lang[26];
bool has[26];
bool cmp(char a,char b)
{
	return lang[a - 'a'] == lang[b - 'a'] ? (a < b):(lang[b - 'a'] < lang[a - 'a']);
}
void floodfill(int r,int c,char from,char to)
{
	if(r < 0 || r >= n || c < 0 || c >= m || arr[r][c] != from)	return;
	arr[r][c] = to;
	for(int i = 0;i < 4;i++) floodfill(r + dr[i],c + dc[i],from,to);
}
int main()
{
//	freopen("in.txt","r",stdin);
	int TC;
	vector<char> clist;
	scanf("%d",&TC);
	for(int TC_ = 1;TC_ <= TC;TC_++)
	{
		printf("World #%d\n",TC_);
		memset(lang,0,sizeof(lang));
		memset(has,false,sizeof(has));
		clist.clear();
		scanf("%d %d",&n,&m);
		for(int i = 0;i < n;i++) scanf("%s",arr[i]);
		for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) if(arr[i][j] != ' ')
		{
			if(!has[arr[i][j]])
			{
				clist.push_back(arr[i][j]);
				has[arr[i][j]] = true;
			}
			lang[arr[i][j] - 'a']++;
			floodfill(i,j,arr[i][j],' ');
		}
		sort(clist.begin(),clist.end(),cmp);
		for(vector<char>::iterator it = clist.begin();it < clist.end();it++)
			printf("%c: %d\n",*it,lang[*it - 'a']);
	}
	return 0;
}
