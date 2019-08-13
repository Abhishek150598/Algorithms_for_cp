//Query and update operations in Binary Indexed Tree
#include<bits/stdc++.h>

using namespace std;

int *BITree;
int N;
int prefix_sum(int index)
{
	int sum=0;
	index=index+1;//For 0 based indexing
	while(index>0)
	{
		sum+=BITree[index];
		index-=index&(-index);
	}
	return sum;
}

void update(int index, int val)
{
	index=index+1;//For 0 based indexing
	while(index<=N)
	{
		BITree[index]+=val;
		index+=index&(-index);
	}
}

void constructBIT(int* arr, int n)
{
	BITree=new int[n+1];
	N=n;
	
	for(int i=1;i<=n;i++)
		BITree[i]=0;
	
	for (int i=0; i<n; i++) 
        update(i, arr[i]);

}
