//COIN CHANGE PROBLEM
#include<bits/stdc++.h>
#define max_int 999999
using namespace std;

int minc[1000]={0};

//PRINTING ALL THE REQUIRED DENOMINATIONS
void find_den(int *arr,int n,int sum, int *T)
{
	cout<<"The denominations reqd are:\n";
	int i,j,k,s=sum;
	while(s!=0)
	{
		for(j=0;j<n;j++)
		{
			if(s-arr[j]>=0)
			{
				k=T[s-arr[j]];
				if(k==(T[s]-1))
				{
					cout<<arr[j]<<" ";
					s=s-arr[j];
					break;
				}
					
			}
			
		}
	}
	cout<<endl;
}

int mincoins(int *arr,int n,int sum)
{
	if(sum==0)
	{
		return 0;
	}
	if(sum<0)
	{
		return max_int;
	}

	if(minc[sum]!=0)
	{
		return minc[sum];
	}
	int min=max_int;
	int k;
	for(int i=0;i<n;i++)
	{
		k=mincoins(arr,n,sum-arr[i]);
		if(k<min)
		{
			min=k;
		}
		
		
	}
	minc[sum]=1+min;
	return (1+min);
}

//TABULATION
int mincoins2(int *arr,int n,int sum)
{
	int *T=new int[sum+1];
	T[0]=0;
	int i,j,k,min;
	for(i=1;i<=sum;i++)
	{
		min=max_int;
		for(j=0;j<n;j++)
		{
			if(i-arr[j]>=0)
			{
				k=T[i-arr[j]];
				if(k<min)
					min=k;
			}
			
		}
		T[i]=min+1;
	}
	if(T[sum]!=max_int+1)
		find_den(arr,n,sum,T);
	
	return T[sum];
}
int main()
{
	int arr[100],n,sum;
	
	cout<<"Enter no of denominations\n";
	cin>>n;
	cout<<"Enter the denominations\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the required sum\n";
	cin>>sum;
	int p=mincoins2(arr,n,sum);
	if(p==max_int+1)
		cout<<"Not possible\n";
	else
		cout<<"Minimum coins requied is: "<<p;
	
	
}
