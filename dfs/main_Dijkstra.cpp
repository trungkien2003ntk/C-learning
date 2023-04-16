#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <list>
#include <map>

using namespace std;
//============================================================================
// START PROGRAM
//============================================================================

class Dijsktra {
//	Declaration
	public:
		int nodes, edges;
		map<pair<int,int>,int> adj;
		list<int> visited, unvisited;
		vector<int> distance;

		// Initializer
		Dijsktra() {
			FILE *fp;
			fp = fopen("GIAOTHONG.inp", "r");
			fscanf(fp, "%d %d", &nodes, &edges);
			distance.resize(nodes+1);
			fill(distance.begin()+1,distance.end(),INT_MAX);
			distance[0]=0;

			int s,d,w;
			for (int i = 0; i < edges; i++) {
				fscanf(fp, "%d %d %d", &s, &d, &w);
//				printf("%d %d %d \n",s,d,w);
//				adj[s].push_back(make_pair(w, d));
				adj[make_pair(s,d)] = w;
			}
			fclose(fp);
		}


		void dealer(int input_vertex) {
			if (visited.size()< nodes) {
				int min_neighbor = 0;
				for (auto &i: unvisited) {
					if (distance[input_vertex] + adj[make_pair(input_vertex,i)] < distance[i])
						distance[i] = distance[input_vertex] + adj[make_pair(input_vertex,i)];
					if (distance[i] > distance[min_neighbor])
						min_neighbor = i;
					printf("%d %d \n",i,min_neighbor);
				}

				visited.emplace_back(min_neighbor);
				unvisited.remove(min_neighbor);

				printf("Visited: ");
				for (auto &i: visited)
					printf("%d ",i);
				printf("Unvisted: ");
				for (auto &i: unvisited)
					printf("%d ",i);



				dealer(min_neighbor);
			}
		}

// Dijsktra
		void solver() {
			visited.emplace_back(1);
			for (int i=2; i<=nodes; i++)
				unvisited.emplace_back(i);
			dealer(1);
		}
};

int main() {
	Dijsktra obj;
	obj.solver();
}
