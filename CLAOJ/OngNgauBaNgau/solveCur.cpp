#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================

vector<vector<pair<long long, long long>>> adj[100008];
vector<long long> dis[100008], parent[100008];
vector<bool> visited[100008];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
long long n, m, s, t;

void dijkstra()
{
    pair<long long, long long> curNode = q.top();
    q.top();
    for (auto it : adj[curNode.first])
    {
        if (it.first == t)
        {
            parent[t] = curNode.first;
            trackMeet();
        }
        else
        {
            parent[it] = curNode.first;
            q.push({});
        }
    }
}

int main()
{
    fast_io;
    // Input data and init solution
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    for (int i = 1; i <= n; i++)
        it = LONG_LONG_MAX;
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
        visited[i] = false, parent[i] = -1;

    // Solve
    q.push({s, 0});
    dis[s] = 0;
    dijkstra();

    // getchar();
}