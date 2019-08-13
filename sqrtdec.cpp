//Square root decomposition
#include<bits/stdc++.h>
#define max 1000000
#define maxsqrt 1000
using namespace std;

int arr[max];
int block[maxsqrt];
int block_size;

void update(int index, int value)
{
	int block_no=index/block_size;
	block[block_no]=block[block_no]-arr[index]+value;
	arr[index]=value;
}

int query(int l,int r)
{
	int sum=0;	
	while(l<=r&&l%block_size!=0)
	{
		sum=sum+arr[l];
		l++;
	}
	while(l+block_size<=r)
	{
		sum=sum+block[l/block_size];
		l=l+block_size;
	}
	while(l<=r)
	{
		sum=sum+arr[l];
		l++;
	}
	
	return sum;
	
}

void preprocess(int *input, int n)
{
	block_size=sqrt(n);
	int j=-1;
	for(int i=0;i<n;i++)
	{
		arr[i]=input[i];
		if(i%block_size==0)
		{
			j++;
			block[j]=0;
		}
		block[j]+=arr[i];
	}
}

