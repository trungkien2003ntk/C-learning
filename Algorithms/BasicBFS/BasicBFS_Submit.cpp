#include <stdio.h>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> Graph;
vector<bool> visited;
queue<int> vertex;

void nhap()
{
    scanf("%i %i", &n, &m);
    Graph.resize(n + 1);
    visited.resize(n + 1);
    int x, y;
    for (int i = 0; i < m; i++)
    {
        scanf("%i %i", &x, &y);
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    for (int i = 1; i < Graph.size(); i++)
        sort(Graph[i].begin(), Graph[i].end());
}

void bfs(int x)
{
    vertex.push(x);
    visited[x] = true;

    int curr;
    while (!vertex.empty())
    {
        curr = vertex.front();
        printf("%i\n",curr);
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
    nhap();
    int i = 0;
    while (i < n)
    {
        i++;
        if (!visited[i])
            bfs(i);
    }
}
