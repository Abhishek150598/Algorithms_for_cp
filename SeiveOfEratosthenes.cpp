//Sieve of Eratosthenes
#include<bits/stdc++.h>
using namespace std;

void SOE(int n)
{
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	
	for(int p=2;p*p<=n;p++)
	{
		if(prime[p]==true)
		{
			for(int i=p*p;i<=n;i+=p)
			{
				prime[i]=false;
			}
		}
	}
	int count=0;
	for(int i=2;i<=n;i++)
	{
		if(prime[i]==true)
		{
			count++;
			cout<<count<<" "<<i<<endl;
			
		}
	}
	cout<<"Number of primes: "<<count<<endl;
}

int main()
{
	SOE(34000);
}
