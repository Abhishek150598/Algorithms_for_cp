//STRONGLY CONNECTED COMPONENTS USING KOSARAJU'S ALGORITHM
//1 BASED INDEXING FOR VERTICES
#include<bits/stdc++.h>
using namespace std;

#define lli long long int

bool visited[10001];
vector <lli> adjl[10001];
vector <lli> rev_adjl[10001];
stack <lli> s;

//FUNCTION FOR FIRST RECURSIVE DFS
void rec_dfs(lli i)
{
	visited[i]=true;
	
	vector <lli>::iterator it=adjl[i].begin();
	while(it!=adjl[i].end())
	{
		if(!visited[*it])
			rec_dfs(*it);
		it++;
		
	}
	s.push(i);
}

//FUNCTION FOR SECOND RECURSIVE DFS
void rec_dfs2(lli i)
{
	visited[i]=true;
	cout<<i<<" ";
	
	vector <lli>::iterator it=rev_adjl[i].begin();
	while(it!=rev_adjl[i].end())
	{
		if(!visited[*it])
			rec_dfs2(*it);
		it++;
		
	}
	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif 
	
	lli i,V,E,a,b;
	//Taking inputs for the graph
	cin>>V>>E;
	for(i=0;i<E;i++)
	{
		cin>>a>>b;
		adjl[a].push_back(b);
	}
	
	//Mark all vertices as not visited (for 1st DFS)
	for(i=1;i<=V;i++) 
        visited[i] = false;
        
	//Performing DFS and storing nodes into a stack
	for(i=1;i<=V;i++) 
	{
		if(!visited[i])
			rec_dfs(i);
	}
    
	//Obtaining the reverse graph
	for(i=1;i<=V;i++)
	{
		vector <lli>::iterator it=adjl[i].begin();
		while(it!=adjl[i].end())
		{
			rev_adjl[*it].push_back(i);
			it++;
		}
	}
	
	//Mark all vertices as not visited (for 2nd DFS)
	for(i=1;i<=V;i++) 
        visited[i] = false;
    
    //Performing 2nd DFS and printing the SCCs
	while(!s.empty())
	{
		lli v=s.top();
		s.pop();
		
		if(!visited[v])
		{
			rec_dfs2(v);
			cout<<endl;
		}
	}
	
}
