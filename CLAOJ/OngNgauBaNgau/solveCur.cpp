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

vector<pair<long long, long long>> adj[100008];
long long dis[100008], parent[100008];
bool visited[100008];
// Create a priority queue for storing the nodes and the distance from s to it
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
long long n, m, s, t, res = LONG_LONG_MAX, resSize = LONG_LONG_MAX;

void showVisited()
{
    cout << "Visited: ";
    for (long long i = 1; i <= n; i++)
        if (visited[i])
            cout << i << " ";
    cout << "\n";
}

void showParent()
{
    for (long long i = 1; i <= n; i++)
        cout << "P[" << i << "] = " << parent[i] << " ";
    cout << endl;
}
void trackBack()
{
    vector<long long> path;
    long long curCity = t;
    path.push_back(t);
    while (curCity != s)
    {
        curCity = parent[curCity];
        path.push_back(curCity);
    }

    if (path.size() == resSize)
        res = min(res, path[resSize / 2]);
    else if ((path.size() & 1) && (path.size() < resSize))
    {
        resSize = path.size();
        res = path[resSize / 2];
    }

    cout << "CURRENT TRACK PATH: \n";
    for (auto it : path)
        cout << it << " ";
    cout << "\n";
}

int main()
{
    fast_io;
    // Input data and init solution
    cin >> n >> m >> s >> t;

    for (long long i = 0; i < m; i++)
    {
        long long x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    for (long long i = 1; i <= n; i++)
        dis[i] = LONG_LONG_MAX;
    dis[s] = 0;
    for (long long i = 1; i <= n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }

    // Solve

    q.push({dis[s], s});

    while (!q.empty())
    {
        auto curNode = q.top();
        q.pop();
        // cout << curNode.first << " " << curNode.second << endl;
        // showVisited();
        // showParent();
        // cout << "PUSH IN: " << "\n";
        visited[curNode.second] = true;
        for (auto it : adj[curNode.second])
        { // Nếu node it chưa được thăm và dis[it.first] > dis[curNode.second] + it.second
            if (!visited[it.first] && dis[it.first] >= dis[curNode.second] + it.second)
            {
                dis[it.first] = dis[curNode.second] + it.second;
                parent[it.first] = curNode.second;

                // cout << "(" << dis[it.first] << "; " << it.first << "); ";
                q.push({dis[it.first], it.first});
            }
            if (it.first == t)
                trackBack();
        }
        // cout << "\n*****************************\n";
    }

    if (res == LONG_LONG_MAX)
        cout << "CRY";
    else
        cout << res;
    // getchar();
}