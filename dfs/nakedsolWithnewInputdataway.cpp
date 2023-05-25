#include <stdio.h>
#include <vector>
#include <stdlib.h>


using namespace std;
//============================================================================
// START PROGRAM
//============================================================================
int n, m;
unsigned long amount = 0, sz = 0;
int size_path = 2147483647;

vector<int> len_route;
vector<bool> visited;
vector<vector<int>> route;
int weight[5001][5001];

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
            if (sz + weight[x][route[x][i]] <= size_path)
                if (!visited[route[x][i]])
                {
                	printf("DFS at %d . Current min size: %d . Current sz: %d \n",x,size_path,sz);
                    sz += weight[x][route[x][i]];
                    dfs(route[x][i]);
                    sz -= weight[x][route[x][i]];
                }
    visited[x] = 0;
}

int main()
{
	FILE *fi, *fo;
	fi = fopen("GIAOTHONG.txt","r");
	fscanf(fi,"%d %d",&n,&m);
	
	route.resize(n + 1);
    visited.resize(n + 1);
	
	int u,v,l;
    for (int i = 0; i < m; i++)
    {
    	printf("Reading line %d \n",i);
        fscanf(fi,"%d %d %d",&u,&v,&l);
        route[u].push_back(v);
        route[v].push_back(u);
        weight[u][v] = weight[v][u] = l;

    }
	fclose(fi);
		
    dfs(1);
	fo = fopen("GIAOTHONG.out","w");
	fprintf(fo,"%d %d",size_path,amount);
	fclose(fo);
}