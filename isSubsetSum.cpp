//Recursive program to find if there is a subset with given sum
#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int *arr, int n, int sum)
{
	if(sum==0)
		return true;
	if(n==0&&sum!=0)
		return false;
	if(arr[n-1]>sum)
		return isSubsetSum(arr,n-1,sum);
		
	return isSubsetSum(arr,n-1,sum)||isSubsetSum(arr,n-1,sum-arr[n-1]);
}
int main()
{
	int arr[]={12,45,23,13,11,62,17};
	cout<<isSubsetSum(arr,7,47)<<endl;
	cout<<isSubsetSum(arr,7,91)<<endl;
	cout<<isSubsetSum(arr,7,68)<<endl;
	cout<<isSubsetSum(arr,7,94)<<endl;
}
