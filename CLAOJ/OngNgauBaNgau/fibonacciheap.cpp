#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================

vector<pair<int, int>> a[1001];
pair<int, int> temp;
int disO[1001], disB[1001], n, m, s, t, u, kc, v, w, x, y, z, res = INT_MAX, resTime = INT_MAX;

// Fibonacci Heap
// Node structure for the Fibonacci Heap
struct Node
{
    int key;
    int degree;
    Node *parent;
    Node *child;
    Node *left;
    Node *right;
    bool mark;

    Node(int key) : key(key), degree(0), parent(nullptr), child(nullptr), left(this), right(this), mark(false) {}
};

// Fibonacci Heap class
class FibonacciHeap
{
private:
    Node *min;
    int nH; // Number of nodes in the heap

    // Link two nodes as children
    void Fibonnaci_link(Node *child, Node *parent)
    {
        child->parent = parent;
        if (parent->child == nullptr)
        {
            parent->child = child;
            child->right = child;
            child->left = child;
        }
        else
        {
            child->right = parent->child;
            child->left = child->right->left;
            parent->child->left->right = child;
            parent->child->left = child;
        }
        parent->degree++;
        child->mark = false;
    }

public:
    // Initialize an empty heap
    FibonacciHeap() : min(nullptr), nH(0) {}

    // Create a new node
    Node *Create_node(int key)
    {
        return new Node(key);
    }

    // Insert a new node into the heap
    void Insert(Node *node)
    {
        min = (min == nullptr) ? node : (node->key < min->key) ? node
                                                               : min;
        node->left = node;
        node->right = node;
        nH++;
    }

    // Union of two Fibonacci heaps
    FibonacciHeap *Union(FibonacciHeap *other)
    {
        FibonacciHeap *newHeap = new FibonacciHeap();
        newHeap->min = (min == nullptr || (other->min != nullptr && other->min->key < min->key)) ? other->min : min;
        newHeap->min->left->right = other->min;
        newHeap->min->right->left = other->min->left;
        other->min->left = newHeap->min->left;
        other->min->right = newHeap->min;
        nH += other->nH;
        other->nH = 0;
        return newHeap;
    }

    // Extract the node with minimum key
    Node *Extract_Min()
    {
        if (min == nullptr)
        {
            return nullptr;
        }
        Node *z = min;

        // Handle children of min node
        if (min->child != nullptr)
        {
            Node *child = min->child;
            do
            {
                child->parent = nullptr;
                child = child->right;
            } while (child != min->child);
            consolidate(min->child);
        }

        // Remove min node from root list
        if (min->left == min)
        {
            min = nullptr;
        }
        else
        {
            min->left->right = min->right;
            min->right->left = min->left;
            min = min->right;
        }

        nH--;
        // Call cascading cut
        if (min != nullptr)
        {
            cut(min, nullptr);
        }

        return z;
    }

    // Cascading cut operation
    void cut(Node *x, Node *y)
    {
        x->left->right = x->right;
        x->right->left = x->left;
        nH--;

        if (y != nullptr)
        {
            y->child = x;
            x->parent = y;
            x->right = y->child;
            x->left = x->right->left;
            y->child->left->right = x;
            y->child->left = x;
            y->degree++;
            x->mark = false;
        }
        else
        {
            x->parent = nullptr;
            x->left = x;
            x->right = x;
            min = x;
        }
    }

    // Link cutting (merging trees with same degree)
    void consolidate()
    {
        int degree = 0;
        // Create an array to store root nodes with the same degree
        Node *[] A = new Node *[nH];
        for (int i = 0; i < nH; ++i)
            A[i] = nullptr;

        Node *x = min;
        Node *w = nullptr;

        do
        {
            Node *next = x->right;
            int d = x->degree;
            while (A[d] != nullptr)
            {
                Node *y = A[d];
                if (x->key > y->key)
                    swap(x, y);
                Fibonnaci_link(y, x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
            x = next;
        } while (x != min);

        min = nullptr;
        for (int i = 0; i < nH; ++i)
        {
            if (A[i] != nullptr)
                if (min == nullptr)
                    min = A[i];
                else
                {
                    min->left->right = A[i];
                    A[i]->left = min->left;
                    A[i]->right = min;
                    min->left = A[i];
                    if (A[i]->key < min->key)
                        min = A[i];
                }
        }

        delete[] A;
    }

    // Decrease key of a node
    void Decrease_Key(Node *x, int key)
    {
        if (key > x->key)
        {
            return;
        }
        x->key = key;
        if (x->parent != nullptr && x->key < x->parent->key)
        {
            cut(x, x->parent);
            cascading_cut(x->parent);
        }
        if (x->key < min->key)
        {
            min = x;
        }
    }

    // Cascading cut operation (helper for Decrease_Key)
    void cascading_cut(Node *y)
    {
        Node *z = y->parent;
        while (z != nullptr && z->mark)
        {
            cut(z, z->parent);
            z = z->parent;
        }
        if (z != nullptr)
        {
            z->mark = true;
        }
    }
};

// int main()
// {
//     FibonacciHeap heap;

//     // Insert some nodes
//     heap.Insert(heap.Create_node(10));
//     heap.Insert(heap.Create_node(4));
//     heap.Insert(heap.Create_node(15));
//     heap.Insert(heap.Create_node(8));

//     // Extract minimum node
//     Node *minNode = heap.Extract_Min();
//     std::cout << "Extracted minimum: " << minNode->key << std::endl;

//     // Decrease key of a node
//     Node *node = heap.min; // Assuming you have a way to access a node
//     heap.Decrease_Key(node, 2);

//     // ... (further operations on the heap)

//     return 0;
// }

// End Fibonacci Heap

void dijkstra(int x, int dis[])
{
    dis[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({dis[x], x});

    while (!q.empty())
    {
        temp = q.top();
        q.pop();
        u = temp.second, kc = temp.first;
        if (kc > dis[u])
            continue;
        for (auto i : a[u])
        {
            v = i.first, w = i.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main()
{
    fast_io;

    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        a[x].push_back({y, z});
        a[y].push_back({x, z});

        disO[x] = disB[y] = 1e9;
        disO[y] = disB[x] = 1e9;
    }

    dijkstra(s, disO);
    dijkstra(t, disB);

    for (int i = 1; i <= n; i++)
        if (disO[i] == disB[i] && disO[i] > 0 && (resTime > disO[i] || (resTime == disO[i] && res > i)))
        {
            res = i;
            resTime = disO[i];
        }
    if (res != INT_MAX)
        cout << res;
    else
        cout << "CRY";
    // getchar();
}
