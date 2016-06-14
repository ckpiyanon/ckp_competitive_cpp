#include <bits/stdc++.h>

using namespace std;

class node {
public:
	int val,sum,ans;
	node *l,*r,*p;
	node(int val):val(val) {}
	node(int val,node* l,node* r)
	{
		this->val = val;
		this->l = l;
		this->r = r;
		this->p = NULL;
		if(l)	l->p = this;
		if(r)	r->p = this;
		sum = 0;
		ans = 2e9;
	}
};

char ino[100001],pos[100001];
int ii[10010],ip[10010];

void destroy_tree(node *root)
{
	if(root == NULL)	return;
	destroy_tree(root->l);	destroy_tree(root->r);
	if(root->l)	delete root->l;
	if(root->r)	delete root->r;
}
int find_index(int *arr,int start,int stop,int val)
{
	for(int i = start;i <= stop;i++)	if(arr[i] == val)	return i;
	return -1;
}
node* construct_tree(int bp,int ep,int bi,int ei)
{
	int val = ip[ep];
	int p = find_index(ii,bi,ei,val);
	int numr = ei - p;
	node *l = p > bi ? construct_tree(bp,ep-numr-1,bi,p-1):NULL;
	node *r = p < ei ? construct_tree(ep-numr,ep-1,p+1,ei):NULL;
	return new node(val,l,r);
}
void calc(node* tree)
{
	node *l = tree->l,*r = tree->r;
	if(l == NULL && r == NULL)
	{
		tree->sum = tree->val;
		tree->ans = tree->val;
		return;
	}
	if(l == NULL)
	{
		calc(r);
		tree->sum = tree->val + r->sum;
		tree->ans = r->ans;
		return;
	}
	if(r == NULL)
	{
		calc(l);
		tree->sum = tree->val + l->sum;
		tree->ans = l->ans;
		return;
	}
	calc(l); calc(r);
	if(l->sum < r->sum)
	{
		tree->sum = l->sum + tree->val;
		tree->ans = l->ans;
	}
	else if(l->sum > r->sum)
	{
		tree->sum = r->sum + tree->val;
		tree->ans = r->ans;
	}
	else if(l->sum == r->sum)
	{
		tree->sum = l->sum + tree->val;
		tree->ans = min(l->ans,r->ans);
	}
}

int main()
{
	char *tok;
	int idx;
	node *root;
	while(gets(ino))
	{
		gets(pos);
		tok = strtok(ino," ");
		idx = 0;
		while(tok)
		{
			ii[idx++] = atoi(tok);
			tok = strtok(NULL," ");
		}
		tok = strtok(pos," ");
		idx = 0;
		while(tok)
		{
			ip[idx++] = atoi(tok);
			tok = strtok(NULL," ");
		}
		root = construct_tree(0,idx-1,0,idx-1);
		calc(root);
		printf("%d\n",root->ans);
		destroy_tree(root);
		delete root;
	}

	return 0;
}
