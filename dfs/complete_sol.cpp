#include <bits/stdc++.h>
#include <vector>
// Policy-based data structures - Co the build indexed_set
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
using namespace std;
// Pre Definitions CONSTANTS
#define PB push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//============================================================================
// START PROGRAM
//============================================================================
int n, m, size_path = INT_MAX, amount = 0, sz = 0;

vector<vector<int>> route;
vector<char> visited;
vector<vector<int>> path;
void nhap()
{
    ifstream f("GIAOTHONG.inp");
    f >> n >> m;
    route.resize(n + 1);
    path.resize(n + 1);
    visited.resize(n + 1);
    int u, v, l;
    for (int i = 0; i < m; i++)
    {
        f >> u >> v >> l;
        route[u].PB(v);
        route[v].PB(u);
        path[u].PB(l);
        path[v].PB(l);
    }
    f.close();
}

void dfs(int x)
{
    visited[x] = 1;
    if (x == n)
    {
        if (sz == size_path)
            amount++;
        else if (sz < size_path)
        {
            amount = 1;
            size_path = sz;
        }
    }
    else
        for (int i = 0; i < route[x].size(); i++)
            if (sz + path[x][i] <= size_path)
                if (!visited[route[x][i]])
                {
                    sz += path[x][i];
                    dfs(route[x][i]);
                    sz -= path[x][i];
                }

    visited[x] = 0;
}

void xuat()
{
    ofstream f("GIAOTHONG.out");
    f << size_path << " " << amount;
    f.close();
}

signed main()
{
	fast_io;
    nhap();
    dfs(1);
    xuat();
}