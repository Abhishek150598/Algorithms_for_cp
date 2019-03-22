//Converting to binary
#include<bits/stdc++.h>
#define lli long long int 
using namespace std;

//ITERATIVE APPROACH
/*lli to_binary(lli N)
{
	lli sum=0,rem,p=1;
	while(N!=0)
	{
		rem=N%2;
		N=N/2;
		sum+=rem*p;
		p*=10;
	}
	return sum;
}*/

//RECURSIVE APPROACH
lli to_binary(lli N)
{
	if(N==0)
		return 0;
	else
		return N%2+10*to_binary(N/2);
}
int main()
{
	lli N,M;
	cin>>N;
	M=to_binary(N);
	cout<<M;
	
}
