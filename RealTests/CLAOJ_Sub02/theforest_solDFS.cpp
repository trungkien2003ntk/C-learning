#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int N, K;
vector<int> dayOfV,result;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Graph class represens a directed graph
// using adjency list representation
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices reachable from v
    void DFS(int v, int steps, int day);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list
}

void Graph::DFS(int v, int steps, int day)
{
    // Mark the current node as visited
    visited[v] = true;
    if (dayOfV[v]==day)
        result[day] = max(result[day],steps);
//	cout << v << " - Steps = " << steps << " - Days = " << day << " - Result[day] = " << result[day] << " - dayOfV[v] = " << dayOfV[v] << endl;
	
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
        {
            DFS(*i, ++steps, day);
            steps--;
        }
}

// Driven code
int main()
{
    fast();
    Graph g;

    // // Raw input
//     N = 6;
//     K = 2;
//     dayOfV.push_back(0);
//     g.addEdge(1, 3);
//     dayOfV.push_back(1);
//     g.addEdge(2, 1);
//     dayOfV.push_back(2);
//     g.addEdge(3, 0);
//     dayOfV.push_back(1);
//     g.addEdge(4, 1);
//     dayOfV.push_back(2);
//     g.addEdge(5, 1);
//     dayOfV.push_back(2);
//     g.addEdge(6, 5);
//     dayOfV.push_back(1);
//     g.addEdge(3, 1);
//     g.addEdge(1, 2);
//     g.addEdge(1, 4);
//     g.addEdge(1, 5);
//     g.addEdge(5, 6);

     // Real Input
    cin >> N >> K;
    dayOfV.push_back(0);
    int x,y;
    for (int i=1;i<=N;i++){
        cin >> x >> y;
        g.addEdge(i,y); g.addEdge(y,i);
        dayOfV.push_back(x);
    }

    for (int i=0;i<=K;i++)
        result.push_back(0);

    for (int i=1;i<=N;i++)
        {
            g.DFS(i,0,dayOfV[i]);
            for (int j=1;j<=N;j++)
                g.visited[j] = 0;
        }

    for (int i=1;i<=K;i++)
        cout << result[i] << endl;

    return 0;
}