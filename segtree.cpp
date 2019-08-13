#include<bits/stdc++.h>
using namespace std;

class segtree
{
	private:
		int arr[1000];
		int tree[1000];
		int arr_size;
		
		void buildST(int, int, int);
		void updateUtil(int, int, int, int, int);
		int queryUtil(int, int, int, int, int);
	
	public:
		segtree(int*, int);
		void update(int, int);
		int query(int, int);
};

segtree::segtree(int* A, int N)
{
	for(int i=0;i<N;i++)
		arr[i]=A[i];
	arr_size=N;
		
	buildST(1,0,N-1);
}

void segtree::buildST(int node, int start, int end)
{
	if(start==end)
	{
		tree[node]=arr[start];
	}
	
	else
	{
		int mid=(start+end)/2;
		buildST(2*node,start,mid);
		buildST(2*node+1,mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1]; //To be modified based on requirement
	}
}

void segtree::updateUtil(int node, int start, int end, int index, int val)
{
	if(start==end)
	{
		arr[index]+=val;
		tree[node]+=val;
	}
	
	else
	{
		int mid=(start+end)/2;
		if(start<=index&&index<=mid)	
			updateUtil(2*node,start,mid,index,val);
		else
			updateUtil(2*node+1,mid+1,end,index,val);
		tree[node]=tree[2*node]+tree[2*node+1]; //To be modified based on requirement
	}
}

int segtree::queryUtil(int node, int start, int end, int l, int r)
{
	if(r<start||l>end)
	{
		return 0;
	}
	if(l<=start&&r>=end)
	{
		return tree[node];
	}
	
	int mid=(start+end)/2;
	int lq=queryUtil(2*node,start,mid,l,r);
	int rq=queryUtil(2*node+1,mid+1,end,l,r);
	return (lq+rq); //To be modified based on requirement
}

void segtree::update(int index, int val)
{
	updateUtil(1,0,arr_size-1,index,val);
}

int segtree::query(int l, int r)
{
	return queryUtil(1,0,arr_size-1,l,r);
}
