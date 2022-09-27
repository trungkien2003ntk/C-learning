//Dijkstra's Algorithm (Using priority queue)
//Watch Striver graph series on youtube I learned from there
#include<bits/stdc++.h>
using namespace std;
void addedge(vector<pair<int,int>>adj[],int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void Dijkstra(vector<pair<int,int>>adj[],int source,int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> prior; //Min-Heap storing will store distance and node
    vector<int>dist(n,INT_MAX);
    dist[source]=0;
    prior.push(make_pair(0,source));
    while(!prior.empty())
    {
        int distance=prior.top().first;
        int node=prior.top().second;
        prior.pop();
        for(auto it:adj[node])
        {
            int next_node=it.first;
            int next_weight=it.second;
            if(dist[next_node]>distance+next_weight)
            {
                dist[next_node]=dist[node]+next_weight;
                prior.push(make_pair(dist[next_node],next_node));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
}
int main()
{
    int vertex,edges;
//    cout<<"ENTER THE NUMBER OF VERTEX AND EDGES:"<<endl;
	ifstream fi("GIAOTHONG.inp");
    fi>>vertex>>edges;
    vector<pair<int,int>>adj[vertex];
    int a,b,w;
//    cout<<"ENTER THE LINK AND THEN WEIGHT:"<<endl;
    for(int i=0;i<edges;i++)
    {
        fi>>a>>b>>w;
        addedge(adj,a,b,w);
    }
    int source = 1;
//    cout<<"ENTER THE SOURCE NODE FROM WHICH YOU WANT TO CALCULATE THE SHORTEST DISTANCE:"<<endl;
    Dijkstra(adj,source,vertex);
    return 0;
}