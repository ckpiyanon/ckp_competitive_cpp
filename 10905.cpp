#include <bits/stdc++.h>

using namespace std;

int cmp(const void *a,const void *b)
{
	char s1[210],s2[210];
	memcpy(s1,a,100);	memcpy(s2,b,100);
	memcpy(s1 + strlen(s1),b,100);	memcpy(s2 + strlen(s2),a,100);
	return strcmp(s2,s1);
}
int cmp2(const void *aa,const void *bb)
{
	char *a = (char*)aa,*b = (char*)bb,*ea = a + strlen(a),*eb = b + strlen(b);
	int i = 0,j = 0;
	for(;a[i] == b[j];i++,j++)
	{
		if(a + i == ea)	a = b,i = -1;
		if(b + j == eb)	b = a,j = -1;
		if(a + i == eb && b + j == ea)	return 0;
	}
	return b[j] - a[i];
}

char arr[50][100];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(~scanf("%d",&n) && n)
	{
		for(int i = 0;i < n;i++)	scanf("%s",arr[i]);
		qsort(arr,n,sizeof(arr[0]),cmp2);
		for(int i = 0;i < n;i++)	printf("%s",arr[i]);
		printf("\n");
	}

	return 0;
}
