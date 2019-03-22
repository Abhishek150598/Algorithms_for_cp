//Largest common subsequence
#include<bits/stdc++.h>
using namespace std;

void getLCS(string s1,string s2, int T[101][101])
{
	int i=s1.length();
	int j=s2.length();
	int k=0;
	char str[101];
	while(T[i][j]!=0)
	{
		if(T[i][j]==T[i-1][j])
			i--;
		else if(T[i][j]==T[i][j-1])
			j--;
		else
		{
			str[k]=s1[i-1];
			i--;
			j--;
			k++;
		}
	}
	cout<<"The longest common substring is:\n";
	for(i=k-1;i>=0;i--)
	{
		cout<<str[i];
	}
	cout<<endl;
	
}
int LCS(string s1,string s2)
{
	int l1=s1.length();
	int l2=s2.length();
	
	int T[101][101];
	
	for(int i=0;i<=l1;i++)
		T[i][0]=0;
		
	for(int j=0;j<=l2;j++)
		T[0][j]=0;
		
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1])
				T[i][j]=T[i-1][j-1]+1;
			else
				T[i][j]=max(T[i-1][j],T[i][j-1]);
		}
		
	}
	getLCS(s1,s2,T);
	return T[l1][l2];
}

int main()
{
	int T;
	string s1,s2;
	cin>>T;
	while(T--)
	{
		cin>>s1;
		cin>>s2;
		int k=LCS(s1,s2);
		cout<<k<<endl;
	}
	return 0;
}
