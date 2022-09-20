// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int n, m, result = 0;
vector<int> first_row, second_row;
vector<list<int>> adj;

vector<int> input_by_line()
{
	vector<int> line;
	line.push_back(0);

	char tempt;
	int i = 0;
	cin >> tempt;
	while (i < m)
	{
		while (tempt == '0' && i < m - 1)
		{
			cin >> tempt;
			i++;
		}
		if (tempt == '1')
			line.push_back(i);
		while (tempt == '1' && i < m - 1)
		{
			cin >> tempt;
			i++;
		}
		if (i == m - 1)
		{
			if (tempt == '0' && i > 0)
				line.push_back(i - 1);
			else if (tempt == '1')
				line.push_back(i);
			line[0] += line[line.size() - 1] - line[line.size() - 2] + 1;
			break;
		}
		else if (tempt == '0')
		{
			line.push_back(i - 1);
			line[0] += line[line.size() - 1] - line[line.size() - 2] + 1;
		}
	}
	return line;
}
void create_route()
{
	// Y tuong luu ky tu de giam tai toi da du lieu
	cin >> n >> m;
	first_row = input_by_line();
	// Luu duong di first_row
	adj.resize(first_row[0] + 1);
	unsigned short index1 = 0, index2 = 0;
	for (int i = 1; i < first_row.size() - 1; i += 2)
		if (first_row[i] == first_row[i + 1])
			index1++;
		else
		{
			for (int j = first_row[i]; j < first_row[i + 1]; j++)
			{
				index1++;
				adj[index1].push_back(index1 + 1);
				adj[index1 + 1].push_back(index1);
			}
			index1++;
		}

	if (n > 1)
		for (int i = 2; i <= n; i++)
		{
			second_row = input_by_line();
			second_row[0] += first_row[0];

			// Chen duong di tren second row va Chen duong di giua first row voi second row
			adj.resize(second_row[0] + 1);
			index2 = second_row[0];
			index1 = first_row[0];
			unsigned short t = first_row.size() - 2, tempt;
			// Bien tempt dung de luu xem lui lai bao xa tu first_row[t+1]
			// Bien k o day chi chay tren 1 khoang trong second_row - khong phai la bien chi so cua second_row
			for (int k = second_row.size() - 2; k >= 1; k -= 2)
			{
				while (first_row[t] > second_row[k + 1] && t > 1)
				{
					index1 -= first_row[t + 1] - first_row[t] + 1;
					t -= 2;
				}

				if (second_row[k] == second_row[k + 1])
				{
					if (second_row[k + 1] <= first_row[t + 1])
					{
						tempt = first_row[t + 1] - second_row[k + 1];
						adj[index2].push_back(index1 - tempt);
						adj[index1 - tempt].push_back(index2);
					}
					index2--;
				}
				else
				{
					for (int j = second_row[k + 1]; j >= second_row[k]; j--)
					{
						while (first_row[t] > j && t > 1)
						{
							index1 -= first_row[t + 1] - first_row[t] + 1;
							t -= 2;
						}
						if (j <= first_row[t + 1])
						{
							tempt = first_row[t + 1] - j;
							adj[index2].push_back(index1 - tempt);
							adj[index1 - tempt].push_back(index2);
						}
						index2--;
						adj[index2].push_back(index2 + 1);
						adj[index2 + 1].push_back(index2);
					}
					index2--;
				}
			}

			first_row = second_row;
		}

	//	for (int i=0;i<first_row.size();i++)
	//		cout << first_row[i] << " ";
}

void xuly(){
	int tracker_num = first_row[0];
	vector<bool> visited;
	visited.resize(first_row[0]+1,false);
	
	// Chay queue check mien lien thong
	list<int> queue;
	int s = 1,track_pos = 1;
	while (tracker_num>0){
		// Increase counter of place to bombarding
		result++;
		// Mark the current node as visited and enqueue it
		visited[s] = true;
		tracker_num--;
		queue.push_back(s);
	
		while (!queue.empty()){
			// Dequeue a vertex from queue and print it
			s=queue.front();
			//cout << s << "("<< dat[s].first << ";" << dat[s].second<< ")" << endl;
        	queue.pop_front();
 
        	// Get all adjacent vertices of the dequeued
        	// vertex s. If a adjacent has not been visited,
        	// then mark it visited and enqueue it
        	for (list<int>::iterator adjecent = adj[s].begin(); adjecent!= adj[s].end();adjecent++)
        	{
            	if (!visited[*adjecent])
            	{
                	visited[*adjecent] = true;
                	queue.push_back(*adjecent);
                	tracker_num--;
            	}
    		}
		}
		while (visited[track_pos]==true && track_pos<first_row[0])
			track_pos++;
		s=track_pos;
	}
	cout << result;
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	create_route();
	xuly();
	xuatCheckIP();
	return 0;
}