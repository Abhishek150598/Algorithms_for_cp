//Addition using bitwise operations
#include<bits/stdc++.h>

using namespace std;

//ITERATIVE SOLUTION
/*int add(int a,int b)
{
	int carry;
	while(b!=0)
	{
		carry=a&b;
		a=a^b;
		b=carry<<1;
		
	}
	return a;
}*/

//RECURSIVE SOLUTION
int add(int a,int b)
{
	if(b==0)
		return a;
	else
		return add(a^b,(a&b)<<1);	
	
}
int main()
{
	cout<<add(32,45)<<endl;
}
