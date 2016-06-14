#include <cstdio>
#include <cstring>
#include <cstdlib>

int *arr,*sz;
int ds_find(int n)
{
	int tmp = n,t2;
	while(arr[tmp] != tmp)	tmp = arr[tmp];
	t2 = n;
	while(arr[n] != tmp)	t2 = arr[n],arr[n] = tmp,n = t2;
	return tmp;
}
void ds_merge(int a,int b)
{
	int ra = ds_find(a),rb = ds_find(b);
	if(sz[ra] > sz[rb])
		sz[ra] += sz[rb],arr[rb] = arr[ra];
	else
		sz[rb] += sz[ra],arr[ra] = arr[rb];
}
bool ds_isConnected(int a,int b) {return ds_find(a) == ds_find(b);}
int main()
{
	int TC,n,a,b,suc,uns;
	char s[31];
	TC = atoi(gets(s));
	gets(s);
	while(TC--)
	{
		n = atoi(gets(s));
		arr = new int[n];
		sz = new int[n];
		for(int i = 0;i < n;i++)	arr[i] = i,sz[i] = 1;
		suc = uns = 0;
		while(gets(s))
		{
			if(strlen(s) == 0) break;
			sscanf(&s[2],"%d %d",&a,&b);
			a--,b--;
			if(s[0] == 'q')
			{
				if(ds_isConnected(a,b))
					suc++;
				else
					uns++;
			}
			else ds_merge(a,b);
		}
		printf("%d,%d\n",suc,uns);
		if(TC > 0)	printf("\n");
		delete[] arr;
		delete[] sz;
	}

	return 0;
}
