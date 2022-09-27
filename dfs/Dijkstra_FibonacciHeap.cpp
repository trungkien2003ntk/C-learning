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

// Fibonacci heap
struct node {
    node* parent;
    node* child;
    node* left;
    node* right;
    int key;
};

void dijkstra(int st){
	
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

	// Dijkstra
	dijkstra(1);
	
	fo = fopen("GIAOTHONG.out","w");
	fprintf(fo,"%d %d",size_path,amount);
	fclose(fo);
}