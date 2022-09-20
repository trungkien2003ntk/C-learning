// Bai tap Basic BFS tai link: http://csloj.ddns.net/problem/559
// Giai thuat:  http://shorturl.at/moqG4
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int n, m;
vector<vector<int>> Graph;
vector<bool> visited;
queue<int> vertex;

void nhapFile()
{
    ifstream f;
    f.open("0.in");
    f >> n >> m;

    Graph.resize(n + 1);
    visited.resize(n + 1);

    int x, y;
    for (int i = 0; i < m; i++)
    {
        f >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    f.close();

    for (int i = 1; i < Graph.size(); i++)
        sort(Graph[i].begin(), Graph[i].end());
        
	for (int i=1 ;i< Graph.size();i++){
		for (int j=0;j<Graph[i].size();j++)
			cout << Graph[i][j] << ' ';
		cout << endl;
	}
}

void nhap()
{
    cin >> n >> m;
    Graph.resize(n + 1);
    visited.resize(n + 1);

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    for (int i = 1; i < Graph.size(); i++)
        sort(Graph[i].begin(), Graph[i].end());
        
	for (int i=1 ;i< Graph.size();i++){
		for (int j=0;j<Graph[i].size();j++)
			cout << Graph[i][j] << ' ';
		cout << endl;
	}
}

void bfs(int x)
{
    vertex.push(x);
    visited[x] = true;

    int curr;
    while (!vertex.empty())
    {
        curr = vertex.front();
        cout << curr << endl;
        vertex.pop();
        for (int i = 0; i < Graph[curr].size(); i++)
            if (!visited[Graph[curr][i]])
            {
                vertex.push(Graph[curr][i]);
                visited[Graph[curr][i]] = true;
            }
    }
}

int main()
{
     nhapFile();
//    nhap();
    bfs(1);
}
