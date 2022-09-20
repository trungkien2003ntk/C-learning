// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n, m, result = 0, a[2001] = {0}, b[2001] = {0};
vector<list<int>> adj;

void nhap()
{
	// Y tuong moi loai bo mang dat de giam tai du lieu
	string s1, s2;
	cin >> n >> m;
	// Doi voi dong dau tien
	cin >> s1;
	for (int i = 0; i < m; i++)
		if (s1[i] == '1')
		{
			a[0]++;
			a[i + 1] = a[0];
		}

	// Resize and save route
	adj.resize(a[0] + 1);
	for (int j = 2; j <= m; j++)
		if (a[j] > 0 && a[j - 1] > 0)
		{
			adj[a[j]].push_back(a[j - 1]);
			adj[a[j - 1]].push_back(a[j]);
		}

	if (n == 1)
	{
		for (int j = 0; j <= m; j++)
			b[j] = a[j];
	}
	else
	{
		// Truong hop thu 2 tro di
		for (int i = 2; i <= n; i++)
		{
			// Transport old b to a
			if (b[0] != 0)
			{
				for (int j = 0; j <= m; j++)
					a[j] = b[j];
				fill(b, b + m + 1, 0);
				b[0] = a[0];
			}
			else
				b[0] = a[0];

			// Xu ly xau thu hai
			cin >> s2;
			// Create new b
			for (int j = 0; j < m; j++)
				if (s2[j] == '1')
				{
					b[0]++;
					b[j + 1] = b[0];
				}
			// Resize and save route
			adj.resize(b[0] + 1);
			for (int j = 1; j <= m; j++)
			{
				if (b[j] > 0 && a[j] > 0)
				{
					adj[b[j]].push_back(a[j]);
					adj[a[j]].push_back(b[j]);
				}
				if (b[j] > 0 && b[j - 1] > 0 && j - 1 > 0)
				{
					adj[b[j]].push_back(b[j - 1]);
					adj[b[j - 1]].push_back(b[j]);
				}
			}
			// Reset status
			s1 = s2;
		}
	}
}

void xuatCheckIP()
{
	for (int i = 0; i < adj.size(); i++)
	{
		cout << "Thanh pho thu " << i << " ket noi voi cac thanh pho: ";
		for (auto it = adj[i].begin(); it != adj[i].end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}

void xuly()
{
	int tracker_num = b[0];
	vector<bool> visited;
	visited.resize(b[0] + 1, false);

	// Chay queue check mien lien thong
	list<int> queue;
	int s = 1, track_pos = 1;
	while (tracker_num > 0)
	{
		// Increase counter of place to bombarding
		result++;
		// Mark the current node as visited and enqueue it
		visited[s] = true;
		tracker_num--;
		queue.push_back(s);

		while (!queue.empty())
		{
			// Dequeue a vertex from queue and print it
			s = queue.front();
			// cout << s << "("<< dat[s].first << ";" << dat[s].second<< ")" << endl;
			queue.pop_front();

			// Get all adjacent vertices of the dequeued
			// vertex s. If a adjacent has not been visited,
			// then mark it visited and enqueue it
			for (list<int>::iterator adjecent = adj[s].begin(); adjecent != adj[s].end(); adjecent++)
			{
				if (!visited[*adjecent])
				{
					visited[*adjecent] = true;
					queue.push_back(*adjecent);
					tracker_num--;
				}
			}
		}
		while (visited[track_pos] == true && track_pos < b[0])
			track_pos++;
		s = track_pos;
	}
	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	nhap();
	xuly();
	xuatCheckIP();
	return 0;
}