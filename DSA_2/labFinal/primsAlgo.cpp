#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Prim's Algorithm - Minimum Spanning Tree
// Time Complexity: O(V^2) with adjacency matrix
// Space Complexity: O(V)

// Function to find vertex with minimum key value among unvisited vertices
int findMinKey(vector<int>& key, vector<bool>& inMST, int n) {
    int minKey = INT_MAX;
    int minIndex = -1;
    
    for (int v = 0; v < n; v++) {
        if (!inMST[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim's Algorithm Implementation
void primsAlgorithm(vector<vector<int>>& graph, int n) {
    // Pseudocode:
    // 1. Initialize key[] with infinity (except first vertex = 0)
    // 2. Initialize inMST[] to false for all vertices
    // 3. Initialize parent[] to track MST edges
    // 4. Loop n times:
    //    a. Pick vertex with minimum key not in MST
    //    b. Add to MST
    //    c. Update key values of adjacent vertices
    
    vector<int> key(n, INT_MAX);      // Key values to pick minimum edge
    vector<bool> inMST(n, false);     // Track vertices in MST
    vector<int> parent(n, -1);        // Track parent for MST edges
    
    key[0] = 0;  // Start from vertex 0
    
    // Build MST with n-1 edges
    for (int count = 0; count < n - 1; count++) {
        // Find minimum key vertex not in MST
        int u = findMinKey(key, inMST, n);
        
        if (u == -1) break;  // No more vertices to process
        
        // Add vertex to MST
        inMST[u] = true;
        
        // Update key values of adjacent vertices
        for (int v = 0; v < n; v++) {
            // If edge exists, v not in MST, and weight < key[v]
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Print MST
    cout << "Minimum Spanning Tree (Prim's Algorithm):\n";
    cout << "Edge\tWeight\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        totalWeight += key[i];
    }
    cout << "Total Weight: " << totalWeight << "\n";
}

// Main function
int main() {
    // Example: 5 vertices, undirected weighted graph
    int n = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    primsAlgorithm(graph, n);
    
    return 0;
}
