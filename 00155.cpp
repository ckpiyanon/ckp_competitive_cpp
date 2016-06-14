#include <cstdio>

int dx[] = {1,1,-1,-1},dy[] = {1,-1,1,-1};
int px,py,ans;

void play(int k,int cx,int cy)
{
	if(k == 0 || cx < 0 || cy < 0 || cx > 2048 || cy > 2048)	return;
	if(cx + k >= px && cy + k >= py && cx - k <= px && cy - k <= py)	ans++;
	for(int i = 0;i < 4;i++)	play(k/2,cx + dx[i]*k,cy + dy[i]*k);
}

int main()
{
	int k;
	while(1)
	{
		scanf("%d %d %d",&k,&px,&py);
		if(!k && !px && !py)	break;
		ans = 0;
		play(k,1024,1024);
		printf("%3d\n",ans);
	}

	return 0;
}
