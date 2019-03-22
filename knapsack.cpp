// 0/1 Knapsack problem
#include<bits/stdc++.h>
using namespace std;
struct item
{ 
	int weight;
	int value;
};

//Function for Knapsack
int knapsack(item* items, int n, int total_wt)
{
	int T[100][100];
	
	for(int i=0;i<=n;i++)
		T[i][0]=0;
		
	for(int j=0;j<=total_wt;j++)
		T[0][j]=0;
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=total_wt;j++)
		{
			if(j<items[i].weight)
			{
				T[i][j]=T[i-1][j];
			}
			else
			{
				T[i][j]=max(T[i-1][j],T[i-1][j-items[i].weight]+items[i].value);
			}
		}
	}
	
	return T[n][total_wt];
}

//1 based indexing is required
int main()
{
	int T,N,W;
    cin>>T;
    while(T--)
    {
    	item items[101];
        cin>>N>>W;
        for(int i=1;i<=N;i++)
        {
            cin>>items[i].value;
        }
        for(int i=1;i<=N;i++)
        {
            cin>>items[i].weight;
        }
        int k=knapsack(items,N,W);
        cout<<k<<endl;
    }
}
