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

vector<pair<int, int>> a[1001];
int disO[1001], disB[1001];

void dijikstra(int x, int dis[])
{
    dis[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({dis[x], x});

    while (!q.empty())
    {
        pair<int, int> temp = q.top();
        q.pop();
        int u = temp.second;
        int kc = temp.first;
        if (kc > dis[u])
            continue;
        for (auto i : a[u])
        {
            int v = i.first;
            int w = i.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main()
{
    fast_io;
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        a[x].push_back({y, z});
        a[y].push_back({x, z});

        disO[x] = disB[y] = 1e9;
        disO[y] = disB[x] = 1e9;
    }

    dijikstra(s, disO);
    dijikstra(t, disB);

    int res = INT_MAX, resTime = INT_MAX;

    for (int i = 1; i <= n; i++)
        if (disO[i] == disB[i] && disO[i] > 0 && (resTime > disO[i] || (resTime == disO[i] && res > i)))
        {
            res = i;
            resTime = disO[i];
        }
    if (res != INT_MAX)
        cout << res;
    else
        cout << "CRY";
    // getchar();
}
