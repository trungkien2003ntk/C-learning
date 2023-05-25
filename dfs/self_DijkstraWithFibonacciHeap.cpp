#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
//============================================================================
// START PROGRAM
//============================================================================

class Node {
	public:
		bool mark;
		int index, key, degree, counter=0;
		Node *parent, *child, *left, *right;
};

Node *create_node(int index, int key) {
	Node *new_node = new Node;
	new_node->index = index;
	new_node->key = key;
	new_node->degree = 0;
	new_node->parent = NULL;
	new_node->left = new_node->right = new_node;
	return new_node;
}

class Dijsktra {
//	Declaration
	public:
		Node *head;
		int nodes, vertices, edges, src, max_deg[14];
		unordered_map<int, Node *> found;
		vector<vector<pair<int, int>>> adj;
		vector<bool> visited;

		// Initializer
		Dijsktra() {
			FILE *fp;
			fp = fopen("GIAOTHONG.inp", "r");
			fscanf(fp, "%d %d", &nodes, &vertices);
			adj.resize(nodes+1);
			visited.resize(nodes+1);
			int s,d,w;
			for (int i = 0; i < vertices; i++) {
				fscanf(fp, "%d %d %d", &s, &d, &w);
				printf("%d %d %d \n",s,d,w);
				adj[s].push_back(make_pair(w, d));
			}
			fclose(fp);

			for (int i = 0; i<nodes+1; i++)
				sort(adj[i].begin(),adj[i].end());

//			for (int i=0; i<adj.size(); i++)
//				for (int j=0; j<adj[i].size(); j++)
//					printf("Distance from %d to %d : %d \n", i, adj[i][j].second, adj[i][j].first);
		}

		// Insert a node to heap
		void fib_heap_insert(int index, int key) {
			Node *x = create_node(index, key);
			found[index] = x;
			if (index==1)
				head = x;
			else {
				// Insert Node to current heap
				Node *l1 = head->left;
				Node *l2 = x->left;
				l1->right = x;
				x->left = l1;
				l2->right = head;
				head->left = l2;
			}
		}

		// Create heap
		void create_heap() {
			int index = 1, key = 0;
			fib_heap_insert(index, key);
			key = INT_MAX;
			index++;
			while (index <= vertices)
				fib_heap_insert(index++, key);
		}

		// Show all node in heap
		void show_node() {
			for(int i =1; i<=vertices; i++) {
				printf("Node # %d: Key: %d \n",found[i]->index,found[i]->key);
			}
		}

		// Extract Min and Clean up
		void extract_min_and_clean_up() {

		}
};

int main() {
	Dijsktra obj;
	obj.create_heap();
//	obj.show_node();
}
