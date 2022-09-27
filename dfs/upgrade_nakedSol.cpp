#include <iosfwd>
#include <fstream>
#include <vector>

using namespace std;

//============================================================================
// START PROGRAM
//============================================================================
unsigned short n, m;
unsigned long long amount = 0, sz = 0;
int size_path = 2147483647;

vector<vector<unsigned short>> route;
vector<bool> visited;
unsigned long weight[5001][5001];

void dfs(unsigned short x)
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
        for (short i = 0; i < route[x].size(); i++)
            if (sz + weight[x][route[x][i]] <= size_path)
                if (!visited[route[x][i]])
                {
                    sz += weight[x][route[x][i]];
                    dfs(route[x][i]);
                    sz -= weight[x][route[x][i]];
                }
    visited[x] = 0;
}

int main()
{
    ifstream fi("GIAOTHONG.inp");
    fi >> n >> m;
    route.resize(n + 1);
    visited.resize(n + 1);
    int u, v, l;
    for (int i = 0; i < m; i++)
    {
        fi >> u >> v >> l;
        if (!weight[u][v])
        {
            route[u].push_back(v);
            route[v].push_back(u);
            weight[u][v] = weight[v][u] = l;
        }
    }

    dfs(1);

    ofstream fo("GIAOTHONG.out");
    fo << size_path << " " << amount;
}