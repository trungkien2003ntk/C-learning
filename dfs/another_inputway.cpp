#include <stdio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>

//============================================================================
// START PROGRAM
//============================================================================
int n, m, amount = 0, sz = 0;
int size_path = 2147483647;

std::vector<std::vector<int>> route;
std::vector<bool> visited;
std::vector<std::vector<int>> path;

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

int main()
{
	FILE * fp;
	fp = fopen("GIAOTHONG.inp","r");
	fscanf(fp,"%d %d",&n,&m);
    route.resize(n + 1);
    path.resize(n + 1);
    visited.resize(n + 1);
    int u, v, l;
    for (int i = 0; i < m; i++)
    {
        fscanf(fp,"%d %d %d",&u,&v,&l);
        route[u].push_back(v);
        route[v].push_back(u);
        path[u].push_back(l);
        path[v].push_back(l);
    }
	fclose(fp);
    dfs(1);
	fp = fopen("GIAOTHONG.out","w");
	fprintf(fp,"%d %d",size_path,amount);
}