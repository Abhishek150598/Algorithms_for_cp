#include<bits/stdc++.h>
#define lli long long int
using namespace std;

lli fibo[1000];

lli fib(int n)
{
	if(fibo[n]!=-1)
		return fibo[n];
		
	if(n<=2)
	{
		fibo[n]=n-1;
		return fibo[n];
	}
	
	fibo[n]=fib(n-1)+fib(n-2);
	return fibo[n];
}
int main()
{
	
	memset(fibo, -1, sizeof(fibo));
	int n;
	cin>>n;
	cout<<fib(n);
}
