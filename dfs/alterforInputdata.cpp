#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <set>

using namespace std;
//============================================================================
// START PROGRAM
//============================================================================
unsigned short n, m;
unsigned long amount = 0, sz = 0;
int size_path = 2147483647;

set<vector<int>> path_inset;
vector<int> len_route;
vector<bool> visited;
vector<vector<int>> route;
int weight[5000][5000];

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
	FILE * fp;
	fp = fopen("GIAOTHONG.inp","r");
	fscanf(fp,"%d %d",&n,&m);

    len_route.resize(3);
    for (int i = 0; i < m; i++)
    {
        fscanf(fp,"%d %d %d",&len_route[0],&len_route[1],&len_route[2]);
        path_inset.insert(len_route);
    }
	fclose(fp);
	
	route.resize(n + 1);
    visited.resize(n + 1);
    
    for (auto i: path_inset){
    	weight[i[0]][i[1]]= i[2];
    	route[i[0]].push_back(i[1]);
        route[i[1]].push_back(i[0]);
	}
	
	
    dfs(1);
	fp = fopen("GIAOTHONG.out","w");
	fprintf(fp,"%d %d",size_path,amount);
}