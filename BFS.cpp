#include<iostream>
#include<vector>
#include<queue>


using namespace std;

void create_ad(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void BFS(vector<int> adj[],vector<bool> visited,int source,int number_vertices)
{
	queue <int>q;
	q.push(source);
	visited.at(source)=true;
	while(!q.empty())
	{
		int v=q.front();
		cout<< v <<" ";
		q.pop();
		
		for(int i=0;i < number_vertices ; i++)
		{
			if(!visited[i])
			{
				q.push(i);
				visited.at(i)=true;
			}
		}
	}
}

int main()
{
	
	int number_vertices=6;
	int source=0;
	
	vector<int> adj[number_vertices];
	vector<bool> visited(number_vertices,false);
	
	create_ad(adj,0,1);
	create_ad(adj,0,2);
	create_ad(adj,0,3);
	create_ad(adj,1,4);
	create_ad(adj,1,5);
	create_ad(adj,2,5);
	create_ad(adj,3,3);
	create_ad(adj,4,4);
	create_ad(adj,5,5);
	BFS(adj,visited,source,number_vertices);
	return 0;
}
