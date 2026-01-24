#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
 * PRIM'S ALGORITHM - MINIMUM SPANNING TREE
 * ========================================
 * 
 * Prim's algorithm finds the Minimum Spanning Tree (MST) of a weighted undirected graph.
 * 
 * KEY CONCEPTS:
 * - Spanning Tree: A tree that connects all vertices with exactly (V-1) edges
 * - Minimum Spanning Tree: Spanning tree with minimum total weight
 * - Greedy Approach: Always pick the smallest weight edge that connects a visited and unvisited vertex
 * 
 * HOW IT WORKS:
 * 1. Start with any vertex (usually 0)
 * 2. Mark it as visited
 * 3. Explore all edges from visited vertices
 * 4. Pick the minimum weight edge that leads to an unvisited vertex
 * 5. Mark the new vertex as visited
 * 6. Repeat until all vertices are visited
 * 
 * Time Complexity:
 * - Using simple array: O(V²)
 * - Using priority queue: O(E log V)
 * 
 * Space Complexity: O(V + E)
 */

// ============ EXAMPLE 1: SIMPLE PRIM'S ALGORITHM (Array-based) ============

class PrimsAlgorithmSimple {
public:
    int V;  // Number of vertices
    vector<vector<pair<int, int>>> adj;  // adj[u] = {(v, weight), ...}
    
    PrimsAlgorithmSimple(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    // Add edge to the graph (undirected)
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    // Prim's Algorithm - O(V²) implementation
    int primsAlgorithm() {
        vector<bool> visited(V, false);      // Track visited vertices
        vector<int> key(V, INT_MAX);         // Minimum edge weight for each vertex
        
        key[0] = 0;  // Start from vertex 0
        int mstWeight = 0;
        
        cout << "\nPrim's Algorithm Execution:\n";
        cout << "============================\n";
        
        for (int i = 0; i < V; i++) {
            // Find the minimum key vertex that hasn't been visited
            int minKey = INT_MAX;
            int u = -1;
            
            for (int v = 0; v < V; v++) {
                if (!visited[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }
            
            if (u == -1) break;  // No more vertices to visit
            
            visited[u] = true;
            mstWeight += key[u];
            
            cout << "Step " << (i + 1) << ": Selected vertex " << u 
                 << " with edge weight " << key[u] << "\n";
            
            // Update key values of adjacent vertices
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (!visited[v] && weight < key[v]) {
                    key[v] = weight;
                    cout << "  -> Updated vertex " << v << " key to " << weight << "\n";
                }
            }
        }
        
        return mstWeight;
    }
};

// ============ EXAMPLE 2: PRIM'S WITH PRIORITY QUEUE (More efficient) ============

class PrimsAlgorithmOptimized {
public:
    int V;
    vector<vector<pair<int, int>>> adj;
    
    PrimsAlgorithmOptimized(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    // Prim's Algorithm using min-heap - O(E log V)
    int primsAlgorithmHeap() {
        vector<bool> inMST(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pq stores {weight, vertex}
        
        int mstWeight = 0;
        pq.push({0, 0});  // Start from vertex 0 with weight 0
        
        cout << "\nPrim's Algorithm with Priority Queue:\n";
        cout << "======================================\n";
        
        while (!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (inMST[u]) continue;  // Already processed
            
            inMST[u] = true;
            mstWeight += weight;
            
            cout << "Added vertex " << u << " with weight " << weight << "\n";
            
            // Add all adjacent edges to priority queue
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }
        
        return mstWeight;
    }
};

// ============ EXAMPLE 3: STEP-BY-STEP VISUALIZATION ============

void stepByStepExample() {
    cout << "\n\n========== STEP-BY-STEP EXAMPLE ==========\n";
    cout << "Graph:\n";
    cout << "  0 -- 2 -- 1\n";
    cout << "  |    |    |\n";
    cout << "  4    3    1\n";
    cout << "  |    |    |\n";
    cout << "  2 -- 1 -- 3\n\n";
    
    PrimsAlgorithmSimple prims(4);
    
    // Add edges: (u, v, weight)
    prims.addEdge(0, 1, 2);  // 0-1: weight 2
    prims.addEdge(0, 2, 4);  // 0-2: weight 4
    prims.addEdge(1, 2, 3);  // 1-2: weight 3
    prims.addEdge(1, 3, 1);  // 1-3: weight 1
    prims.addEdge(2, 3, 2);  // 2-3: weight 2
    
    int mstWeight = prims.primsAlgorithm();
    
    cout << "\nMinimum Spanning Tree Weight: " << mstWeight << "\n";
    cout << "Edges in MST: (0-1:2), (1-3:1), (1-2 or 2-3:2)\n";
}

// ============ EXAMPLE 4: PRACTICAL USE CASE ============

void practicalExample() {
    cout << "\n\n========== PRACTICAL EXAMPLE: ROAD NETWORK ==========\n";
    cout << "Cities: 0=New York, 1=Boston, 2=Philadelphia, 3=Washington DC, 4=Atlanta\n";
    cout << "Numbers = distances (in 100 km)\n\n";
    
    PrimsAlgorithmOptimized prims(5);
    
    // City connections and distances
    prims.addEdge(0, 1, 3);  // NY to Boston: 300 km
    prims.addEdge(0, 2, 2);  // NY to Philadelphia: 200 km
    prims.addEdge(1, 2, 2);  // Boston to Philadelphia: 200 km
    prims.addEdge(2, 3, 1);  // Philadelphia to DC: 100 km
    prims.addEdge(2, 4, 7);  // Philadelphia to Atlanta: 700 km
    prims.addEdge(3, 4, 8);  // DC to Atlanta: 800 km
    
    int mstWeight = prims.primsAlgorithmHeap();
    
    cout << "\nMinimum Total Distance: " << (mstWeight * 100) << " km\n";
}

// ============ EXAMPLE 5: COMPARISON TABLE ============

void comparisonAndAnalysis() {
    cout << "\n\n========== ALGORITHM ANALYSIS ==========\n";
    cout << "Prim's vs Kruskal's Algorithm:\n";
    cout << "============================\n\n";
    
    cout << "PRIM'S ALGORITHM:\n";
    cout << "- Time: O(V²) with array, O(E log V) with heap\n";
    cout << "- Space: O(V + E)\n";
    cout << "- Works with: Dense graphs, undirected/directed\n";
    cout << "- Start: Pick any starting vertex\n";
    cout << "- Grows: Always connects to existing MST\n\n";
    
    cout << "KRUSKAL'S ALGORITHM:\n";
    cout << "- Time: O(E log E)\n";
    cout << "- Space: O(V + E)\n";
    cout << "- Works with: Sparse graphs, undirected\n";
    cout << "- Start: Sort all edges by weight\n";
    cout << "- Grows: Connects different components\n\n";
    
    cout << "WHEN TO USE:\n";
    cout << "- Prim's: Dense graphs, graphs with many edges\n";
    cout << "- Kruskal's: Sparse graphs, easier implementation\n";
}

// ============ MAIN FUNCTION ============

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "=========================================\n";
    cout << "  PRIM'S ALGORITHM TUTORIAL\n";
    cout << "  Minimum Spanning Tree\n";
    cout << "=========================================\n";
    
    stepByStepExample();
    practicalExample();
    comparisonAndAnalysis();
    
    cout << "\n=========================================\n";
    cout << "  KEY TAKEAWAYS:\n";
    cout << "=========================================\n";
    cout << "1. Prim's finds MST by growing from a vertex\n";
    cout << "2. Always pick minimum weight edge to new vertex\n";
    cout << "3. Greedy approach - locally optimal choices\n";
    cout << "4. O(V²) simple, O(E log V) with heap\n";
    cout << "5. Works well for dense graphs\n";
    cout << "6. Total weight of MST is unique (if distinct weights)\n";
    
    return 0;
}
