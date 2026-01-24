#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(V, INT_MIN);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    priority_queue<pair<int,int>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v] && w > key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int totalWeight = 0;
    cout << "Vertex   Parent   Key\n";
    for (int i = 0; i < V; i++) {
        cout << i << "        " << parent[i] << "        " << key[i] << "\n";
        if (key[i] != INT_MIN)
            totalWeight += key[i];
    }

    cout << "The weight of the maximum spanning tree is " << totalWeight << "\n";

    return 0;
}
