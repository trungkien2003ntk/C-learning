#include <iosfwd>
#include <fstream>
#include <vector>

using namespace std;
// Pre Definitions CONSTANTS
#define PB push_back
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

//============================================================================
// START PROGRAM
//============================================================================
unsigned short n, m;
unsigned long amount = 0, sz = 0;
int size_path = 2147483647;

vector<vector<unsigned short>> route;
vector<bool> visited;
vector<vector<unsigned short>> path;
bool checker[5000][5000];
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
            if (sz + path[x][i] <= size_path)
                if (!visited[route[x][i]])
                {
                    sz += path[x][i];
                    dfs(route[x][i]);
                    sz -= path[x][i];
                }
    visited[x] = 0;
}

int main()
{
    //    ios_base::sync_with_stdio(0);
    //    cin.tie(0);
    //    cout.tie(0);

    ifstream fi("GIAOTHONG.inp");
    fi >> n >> m;
    route.resize(n + 1);
    path.resize(n + 1);
    visited.resize(n + 1);
    int u, v, l;
    for (int i = 0; i < m; i++)
    {
        fi >> u >> v >> l;
        if (!checker[u][v])
        {
            checker[u][v] = checker[v][u] = 1;
            route[u].PB(v);
            route[v].PB(u);
            path[u].PB(l);
            path[v].PB(l);
        }
    }

    dfs(1);

    ofstream fo("GIAOTHONG.out");
    fo << size_path << " " << amount;
}