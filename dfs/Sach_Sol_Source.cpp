#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> road[1000];
vector<int> mi;
vector<pair<int,int>> length;
bool visited[1000];
int n, m, tong = 0;

void dfs(int x)
{
	{
		for (int i : road[x])
		{
			if (visited[i] == 0)
			{
				tong += length[i][x];
				if (i == n)
				{
					mi.push_back(tong);
					tong = 0; 
				}
				else
				{
					visited[i] = 1;
					dfs(i);
					visited[i] = 0;
				}
			}
		}
	}
}

void final()
{
	sort(mi.begin(), mi.end());
	for (int i : mi)
	{
		if (i == mi[0])
		{
			tong++;
		}
	}

}

int main()
{
	freopen("ipdat.txt","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, l;
		cin >> u >> v >> l;
		length[u][v] = l;
		length[v][u] = l;
		road[v].push_back(u);
	}


	// dfs(1);
	
	// final();

	// cout << mi[0] << " " << tong;
}