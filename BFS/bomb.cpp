// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n,m,des=0;
vector<pair<int,int>> dat;

// Cau truc Graph tinh chinh cho bai tap nay
class Graph{
	int V,tracker_num; // V = So luong diem
	
	vector<list<int>> adj;
	public:
		int result = 0;
		Graph(int V); // Constructor
		
		// function to add 2-way-edge to graph
		void addEdge(int v,int w);
		
		// print BFS traversal from a given source s
		void BFS();
};

Graph::Graph(int V){
	this->V = V;
	this->tracker_num = V;
	adj.resize(V);
}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w); // Add w to v's list 
	adj[w].push_back(v);
}

void Graph::BFS(){
	//  Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(V,false);
	
	// Create a queue for BFS
	list<int> queue;
	int s = 0,track_pos = 0;
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
        	for (auto adjecent: adj[s])
        	{
            	if (!visited[adjecent])
            	{
                	visited[adjecent] = true;
                	queue.push_back(adjecent);
                	tracker_num--;
            	}
    		}
		}
		while (visited[track_pos]==true && track_pos<dat.size())
			track_pos++;
		s=track_pos;
	}
}

bool in_cases(int x,int y){
	if ((dat[x].first == dat[y].first-1 && dat[x].second == dat[y].second) || (dat[x].first == dat[y].first && (dat[x].second == dat[y].second-1 || dat[x].second == dat[y].second+1)))
		return true;
	return false;			
}

void xuly(){
	char tempt;
	// Y tuong moi loai bo mang dat de giam tai du lieu
	string s1,s2;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
		cin >> tempt;
		if (tempt == '1')
			dat.push_back(make_pair(i,j));
	}
	
	// Build Cau truc Graph
	Graph g(dat.size());
	for (int i=0;i<dat.size();i++)
		for (int j=i+1;j<dat.size();j++)
			if (in_cases(i,j))
				g.addEdge(i,j);
	
	g.BFS();
	cout << g.result;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Create a graph given in the above diagram
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 3);
//
// 
//    cout << "Following is Breadth First Traversal "
//         << "(starting from vertex 2) \n";
//    g.BFS(2);
    
	xuly();
//	g.BFS(1);
	return 0;
}