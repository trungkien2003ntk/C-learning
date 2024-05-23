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
int n, m, s, t;

long long w[108][108], d[108][108], trace[108][108], resTime = LONG_LONG_MAX, res = LONG_LONG_MAX;

void init_raw()
{
    for (int i = 0; i < 108; i++)
        for (int j = 0; j < 108; j++)
            d[i][j] = w[i][j] = LONG_LONG_MAX;
}

void floydWarshall()
{
    for (int k = 0; k < n; k++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (d[u][v] > d[u][k] + d[k][v])
                {
                    d[u][v] = d[u][k] + d[k][v];
                    if (u == s && v == t && d[u][k] == d[k][v] && d[u][k] > 0 && ((d[u][k] < resTime) || (d[u][k] == resTime) && (res > k)))
                        res = k, resTime = d[u][k];
                    trace[u][v] = trace[k][v];
                }
}

void xuatD()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << d[i][j] << " \n"[j == n];
}
int main()
{
    fast_io;
    init_raw();

    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            trace[u][v] = u;
    // Input data and init solution
    cin >> n >> m >> s >> t;
    int x, y, z;
    for (long long i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        w[x][y] = w[y][x] = d[x][y] = d[y][x] = z;
    }

    floydWarshall();
    xuatD();

    cout << res << " " << resTime;

    // getchar();
}