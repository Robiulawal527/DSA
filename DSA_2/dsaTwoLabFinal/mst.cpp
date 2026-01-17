#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// ============= PRIM'S ALGORITHM =============
/*
 * Prim's Algorithm:
 * - Start from any vertex
 * - Repeatedly pick the minimum weight edge that connects a visited vertex to an unvisited vertex
 * - Time Complexity: O(V^2) with array, O(E log V) with priority queue
 * - Space Complexity: O(V)
 */

class PrimsAlgorithm {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list: {neighbor, weight}

    PrimsAlgorithm(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add edge (undirected graph)
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Prim's algorithm implementation
    void primsAlgorithm() {
        vector<bool> visited(V, false);
        vector<int> minWeight(V, INT_MAX);
        vector<int> parent(V, -1);
        
        minWeight[0] = 0; // Start from vertex 0
        int totalCost = 0;

        cout << "\n========== PRIM'S ALGORITHM ==========\n";
        cout << "Edge\t\tWeight\n";
        cout << "----\t\t------\n";

        for (int i = 0; i < V; i++) {
            // Find minimum weight vertex not yet visited
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || minWeight[j] < minWeight[u])) {
                    u = j;
                }
            }

            if (minWeight[u] == INT_MAX) break; // Disconnected graph

            visited[u] = true;
            if (parent[u] != -1) {
                cout << parent[u] << " - " << u << "\t\t" << minWeight[u] << "\n";
                totalCost += minWeight[u];
            }

            // Update minimum weights of adjacent vertices
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (!visited[v] && weight < minWeight[v]) {
                    minWeight[v] = weight;
                    parent[v] = u;
                }
            }
        }

        cout << "\nTotal MST Weight (Prim's): " << totalCost << "\n";
    }
};

// ============= KRUSKAL'S ALGORITHM =============
/*
 * Kruskal's Algorithm:
 * - Sort all edges by weight in ascending order
 * - Use Union-Find (Disjoint Set Union) to detect cycles
 * - Pick edges one by one if they don't form a cycle
 * - Time Complexity: O(E log E) for sorting
 * - Space Complexity: O(V)
 */

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find root with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union two sets with union by rank
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false; // Already in same set (cycle detected)

        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;

        return true;
    }
};

class KruskalAlgorithm {
public:
    int V, E;
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };
    vector<Edge> edges;

    KruskalAlgorithm(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // Kruskal's algorithm implementation
    void kruskalsAlgorithm() {
        sort(edges.begin(), edges.end());

        UnionFind uf(V);
        vector<Edge> mst;
        int totalCost = 0;

        cout << "\n========== KRUSKAL'S ALGORITHM ==========\n";
        cout << "Edge\t\tWeight\n";
        cout << "----\t\t------\n";

        for (auto& edge : edges) {
            // If u and v are not in same set, add this edge to MST
            if (uf.unite(edge.u, edge.v)) {
                mst.push_back(edge);
                cout << edge.u << " - " << edge.v << "\t\t" << edge.weight << "\n";
                totalCost += edge.weight;

                if (mst.size() == V - 1) break; // MST complete
            }
        }

        cout << "\nTotal MST Weight (Kruskal's): " << totalCost << "\n";
    }
};

// ============= MAIN FUNCTION =============
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "==== MINIMUM SPANNING TREE (MST) ====\n\n";

    int V = 5; // 5 vertices
    
    // Example 1: Using Prim's Algorithm
    cout << "\n--- Example 1: Prim's Algorithm ---\n";
    PrimsAlgorithm prim(V);
    prim.addEdge(0, 1, 4);
    prim.addEdge(0, 2, 2);
    prim.addEdge(1, 2, 1);
    prim.addEdge(1, 3, 5);
    prim.addEdge(2, 3, 8);
    prim.addEdge(2, 4, 10);
    prim.addEdge(3, 4, 2);
    prim.addEdge(3, 0, 6);

    prim.primsAlgorithm();

    // Example 2: Using Kruskal's Algorithm
    cout << "\n--- Example 2: Kruskal's Algorithm ---\n";
    KruskalAlgorithm kruskal(V, 8);
    kruskal.addEdge(0, 1, 4);
    kruskal.addEdge(0, 2, 2);
    kruskal.addEdge(1, 2, 1);
    kruskal.addEdge(1, 3, 5);
    kruskal.addEdge(2, 3, 8);
    kruskal.addEdge(2, 4, 10);
    kruskal.addEdge(3, 4, 2);
    kruskal.addEdge(3, 0, 6);

    kruskal.kruskalsAlgorithm();

    cout << "\n========================================\n";
    cout << "MST Concepts:\n";
    cout << "1. A tree that connects all vertices with minimum total edge weight\n";
    cout << "2. Has exactly V-1 edges for V vertices\n";
    cout << "3. No cycles present\n";
    cout << "4. Applications: Network design, clustering, etc.\n";

    return 0;
}
