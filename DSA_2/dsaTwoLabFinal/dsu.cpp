#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
 * DISJOINT SET UNION (DSU) / UNION-FIND
 * ====================================
 * 
 * DSU is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets.
 * It supports two main operations:
 * 1. FIND: Returns which subset an element belongs to
 * 2. UNION: Merges two subsets into one
 * 
 * Time Complexity (with path compression & union by rank):
 * - Find: O(α(n)) ≈ O(1) where α is inverse Ackermann function
 * - Union: O(α(n)) ≈ O(1)
 */

// ============ BASIC DSU IMPLEMENTATION ============

class DSU_Basic {
public:
    vector<int> parent;  // parent[i] stores the parent of element i
    
    DSU_Basic(int n) {
        parent.resize(n);
        // Initially, each element is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find the root/representative of element x
    // Without path compression - SLOW O(n)
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    // Union two sets containing x and y
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            parent[rootX] = rootY;  // Make rootY the parent
        }
    }
    
    // Check if two elements are in same set
    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }
};

// ============ OPTIMIZED DSU WITH RANK ============

class DSU_Optimized {
public:
    vector<int> parent;
    vector<int> rank;  // rank[i] = approximate height of tree rooted at i
    
    DSU_Optimized(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find with PATH COMPRESSION
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Compress path
        }
        return parent[x];
    }
    
    // Union by RANK
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;  // Already in same set
        
        // Attach smaller rank tree under larger rank tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // If ranks are same, choose any one and increase its rank
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }
};

// ============ EXAMPLE 1: CONNECTED COMPONENTS ============

void connectedComponents() {
    cout << "\n=== Example 1: Finding Connected Components ===\n";
    
    int n = 5;  // 5 elements: 0, 1, 2, 3, 4
    DSU_Optimized dsu(n);
    
    // Create some connections
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    
    cout << "After unions:\n";
    cout << "0 and 2 in same set? " << (dsu.isSameSet(0, 2) ? "YES" : "NO") << "\n";
    cout << "0 and 3 in same set? " << (dsu.isSameSet(0, 3) ? "YES" : "NO") << "\n";
    cout << "3 and 4 in same set? " << (dsu.isSameSet(3, 4) ? "YES" : "NO") << "\n";
}

// ============ EXAMPLE 2: CYCLE DETECTION IN GRAPH ============

void cycleDetection() {
    cout << "\n=== Example 2: Cycle Detection ===\n";
    
    // Graph edges: (u, v)
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};
    int n = 5;
    
    DSU_Optimized dsu(n);
    bool hasCycle = false;
    
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        
        if (dsu.isSameSet(u, v)) {
            cout << "Cycle detected between " << u << " and " << v << "\n";
            hasCycle = true;
        } else {
            dsu.unite(u, v);
            cout << "Added edge: " << u << " - " << v << "\n";
        }
    }
    
    cout << "Graph has cycle? " << (hasCycle ? "YES" : "NO") << "\n";
}

// ============ EXAMPLE 3: FRIENDS GROUPS ============

void friendsGroups() {
    cout << "\n=== Example 3: Finding Friend Groups ===\n";
    
    int n = 6;  // 6 people: 0-5
    DSU_Optimized dsu(n);
    
    // Friendships
    vector<pair<int, int>> friendships = {
        {0, 1}, {1, 2}, {3, 4}, {5, 5}
    };
    
    for (auto& f : friendships) {
        dsu.unite(f.first, f.second);
    }
    
    cout << "Friend groups (representatives):\n";
    map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
        groups[dsu.find(i)].push_back(i);
    }
    
    for (auto& g : groups) {
        cout << "Group: ";
        for (int person : g.second) {
            cout << person << " ";
        }
        cout << "\n";
    }
}

// ============ EXAMPLE 4: KRUSKAL'S ALGORITHM (MST) ============

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

void kruskalMST() {
    cout << "\n=== Example 4: Kruskal's Algorithm (Minimum Spanning Tree) ===\n";
    
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 3}
    };
    
    // Sort edges by weight
    sort(edges.begin(), edges.end());
    
    DSU_Optimized dsu(n);
    int mstWeight = 0;
    
    cout << "Edges in sorted order:\n";
    for (auto& e : edges) {
        if (!dsu.isSameSet(e.u, e.v)) {
            dsu.unite(e.u, e.v);
            mstWeight += e.weight;
            cout << "Added edge: " << e.u << " - " << e.v << " (weight: " << e.weight << ")\n";
        } else {
            cout << "Skipped edge: " << e.u << " - " << e.v << " (would create cycle)\n";
        }
    }
    
    cout << "Total MST weight: " << mstWeight << "\n";
}

// ============ MAIN FUNCTION ============

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "========================================\n";
    cout << "  DISJOINT SET UNION (DSU) TUTORIAL\n";
    cout << "========================================\n";
    
    connectedComponents();
    cycleDetection();
    friendsGroups();
    kruskalMST();
    
    cout << "\n========================================\n";
    cout << "  KEY TAKEAWAYS:\n";
    cout << "========================================\n";
    cout << "1. DSU tracks disjoint subsets efficiently\n";
    cout << "2. find() returns representative of set\n";
    cout << "3. unite() merges two sets\n";
    cout << "4. Path compression + Union by rank = near O(1) ops\n";
    cout << "5. Useful for: cycle detection, MST, connectivity\n";
    
    return 0;
}
